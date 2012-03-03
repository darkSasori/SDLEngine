#include "Barra.h"

Barra::Barra(std::string lado, int x, int y)
	:Entity(){
	i = Image::createImage(Rect(x,y,20,200), Color(255,255,255));
	Entity::x = x;
	Entity::y = y;
	Entity::w = 20;
	Entity::h = 200;
	setProperty("lado", lado);
}

Barra::~Barra(){
}

void Barra::treat(SDLEngine::Event e){
	switch( e.id ){
	case 1: y -= 5; break;
	case 2: y += 5; break;
	}
}

void Barra::onCollide(SDLEngine::Entity *e){
}

void Barra::draw(){
	i->x = x;
	i->y = y;
	i->draw();
}
