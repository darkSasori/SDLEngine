#include "SDLEngine.h"
#include "Bola.h"
#include "Barra.h"
#include "TestThread.h"

using SDLEngine::List;
using SDLEngine::Size;
using SDLEngine::Rect;
using SDLEngine::Color;
using SDLEngine::Image;
using SDLEngine::ImageGroup;

class Main : public SDLEngine::Application, SDLEngine::EventListener {

	private:
		bool bRun;
		Barra *barra2;
		Barra *barra1;
		Bola *bola;
		int x;
		int y;

	public:
		int main(List<String> args){

			while( bRun ){
				factory->getVideoManager()->beginDraw();
				factory->getEventManager()->process();

				factory->getEntityManager()->collid(bola);

				barra2->draw();
				barra1->draw();
				bola->drawBola();

				printf("FPS: %0.00f\r", factory->getVideoManager()->getTick());
				factory->getVideoManager()->endDraw();
			}
			return 0;
		}

		void init(){
			TestThread *t = new TestThread();
			t->start();
			t->lock();
			x = 800;
			y = 600;

			SDLEngine::YAMLNode info;
			info.LoadFile("resource/teste.yaml");
			bRun = true;

			factory->getVideoManager()->init();
			factory->getVideoManager()->createWindow(info["title"].to<std::string>(), Size(x,y), false);

			barra1 = new Barra("X", 30, 150);
			bola = new Bola(x, y);
			barra2 = new Barra("Y", 770, 150);

			factory->getEventManager()->init();
			factory->getEventManager()->addEventListener(SDL_QUIT, 1, this);
			factory->getEventManager()->addEventListener(SDLK_q, 1, this);
			factory->getEventManager()->addEventListener(SDLK_UP, 1, barra2);
			factory->getEventManager()->addEventListener(SDLK_DOWN, 2, barra2);
			factory->getEventManager()->addEventListener(SDLK_a, 1, barra1);
			factory->getEventManager()->addEventListener(SDLK_z, 2, barra1);


			factory->getEntityManager()->addEntity(barra2);
			factory->getEntityManager()->addEntity(barra1);
			factory->getEntityManager()->addEntity(bola);
		}

		void treat(SDLEngine::Event e){
			switch( e.id ){
			case 1:
				bRun = false;
				break;
			}
		}

}app;
