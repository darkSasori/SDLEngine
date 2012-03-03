#include "Bola.h"

Bola::Bola(int mw, int mh)
	:Entity(){
	i = Image::createImage(Rect(90,30,45,45), Color(0,0,255));
	x = i->x;
	y = i->y;
	w = i->w;
	h = i->h;

	dx = dy = vx = vy = 0;
	this->mw = mw;
	this->mh = mh;
}

Bola::~Bola(){
}

void Bola::onCollide(SDLEngine::Entity *e){
	if( e->getProperty("lado") == "X" )
		dx = 0;
	else
		dx = 1;
}

void Bola::drawBola(){
	if( x+w >= mw )
		dx = 1;
	else if( x <= 0 )
		dx = 0;
	if( y+h >= mh )
		dy = 1;
	else if( y <= 0 )
		dy = 0;

	 if(dx == 0)
		vx = 4;

	 if(dx == 1)
		vx = -4;
	 
	 if(dy == 0)
		vy = 4;

	 if(dy == 1)
		vy = -4;

	 x = i->x += vx;
	 y = i->y += vy;

	 i->draw();
}
