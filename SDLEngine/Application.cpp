#include "Application.h"

NS_BEGIN

Application *Application::m_App = NULL;

Application::Application(){
	factory = Factory::instance();
	Application::m_App = this;
}

Application::~Application(){
	Application::m_App = NULL;
}

void Application::close(){
}

NS_END


int main(int narg, char **carg){
	int r = 0;
	try{
		if( SDLEngine::Application::m_App == NULL )
			throw SDLEngine::Exception("Classe 'Application' nao foi implementada!");

		SDLEngine::List<String> args;
		for( int i = 0; i < narg; i++ ){
			args += carg[i];
		}

		SDLEngine::Application::m_App->init();
		r = SDLEngine::Application::m_App->main(args);
		SDLEngine::Application::m_App->close();
	}
	catch( SDLEngine::Exception e ){
		std::cout << "SDLEngine Exception: " << e.what() << std::endl;
	}
	catch( YAML::ParserException e ){
		std::cout << "YAML Exception: " << e.what() << std::endl;
	}
	catch( std::ifstream::failure e ){
		std::cout << "FStream Exception: " << "" << std::endl;
	}
	catch( std::exception e ){
		std::cout << "STD Exception: " << e.what() << std::endl;
	}
	catch( ... ){
		std::cout << "Erro desconhecido" << std::endl;
	}
	return r;
}
