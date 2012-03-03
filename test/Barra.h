#ifndef __BARRA_H__
#define __BARRA_H__

#include "SDLEngine.h"
using SDLEngine::Color;
using SDLEngine::Image;

class Barra : public SDLEngine::Entity, public SDLEngine::EventListener {
	private:
		SDLEngine::Image *i;

	public:
		Barra(std::string, int, int);
		~Barra();

		void treat(SDLEngine::Event);
		void onCollide(SDLEngine::Entity*);

		void draw();
};

#endif
