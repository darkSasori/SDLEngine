#ifndef __IMAGEENTITY_H__
#define __IMAGEENTITY_H__

#include "SDLEngine.h"

class ImageEntity
	: public SDLEngine::ImageGroup
	, public SDLEngine::Entity {
	private:
		bool collide;
	public:
		ImageEntity(bool);
		~ImageEntity();

		void onCollide(SDLEngine::Entity *);
		void offCollide(SDLEngine::Entity *);

		void setX(float);
		void setY(float);
		float getX();
		float getY();
		float getW();
		float getH();
		bool isCollide();
};

#endif
