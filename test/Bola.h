#ifndef __BOLA_H__
#define __BOLA_H__

#include "SDLEngine.h"
using SDLEngine::Color;
using SDLEngine::Image;

class Bola : public SDLEngine::Entity{
	private:
		SDLEngine::Image *i;
		int dx, dy, vx, vy, mw, mh;

	public:
		Bola(int, int);
		~Bola();

		void onCollide(SDLEngine::Entity*);

		void drawBola();
};

#endif
