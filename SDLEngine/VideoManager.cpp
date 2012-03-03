#include "VideoManager.h"

NS_BEGIN

VideoManager::VideoManager(){
}

VideoManager::~VideoManager(){
}

void VideoManager::init(){

	if( SDL_Init(SDL_INIT_VIDEO) == -1 )
		throw Exception("Nao foi possivel inicial o video!");
	atexit(SDL_Quit);
}

void VideoManager::createWindow(String title, Size size, bool fullscreen){
	m_Title = title;
	m_Size = size;
	m_bFullScreen = fullscreen;

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	uint flags = SDL_HWSURFACE | SDL_HWACCEL | SDL_DOUBLEBUF | SDL_OPENGL;
	if( m_bFullScreen )
		flags |= SDL_FULLSCREEN;
	
	if( SDL_SetVideoMode(m_Size.getWidth(), m_Size.getHeight(), 32, flags) == NULL )
		throw Exception("SDL Erro: %s", SDL_GetError());

	SDL_WM_SetCaption(m_Title.c_str(), NULL);
	
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	glEnable(GL_TEXTURE_2D);
	glDisable(GL_DEPTH_TEST);

	glViewport(0, 0, m_Size.getWidth(), m_Size.getHeight());
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0.0f, m_Size.getWidth(), m_Size.getHeight(), 0.0f, -1.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	setTime(10);
	m_Fps = 0;
	m_Start = SDL_GetTicks();
}

void VideoManager::beginDraw(){
	glClear(GL_COLOR_BUFFER_BIT);
	m_Fps++;
}

void VideoManager::endDraw(){
	SDL_GL_SwapBuffers();
	processTime();
}

void VideoManager::setTime(Uint32 t){
	m_Time = t;
	m_Tick = SDL_GetTicks() + m_Time;
}

Uint32 VideoManager::getTime(){
	return m_Tick - SDL_GetTicks();
}

float VideoManager::getTick(){
	return m_Fps / (float)(SDL_GetTicks() - m_Start) * 1000;
}

void VideoManager::processTime(){
	Uint32 n = SDL_GetTicks();
	if( m_Tick > n ){
		SDL_Delay(m_Tick - n);
		m_Tick += m_Time;
	}
}

NS_END
