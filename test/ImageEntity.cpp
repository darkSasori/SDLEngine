#include "ImageEntity.h"

ImageEntity::ImageEntity(bool r)
	:ImageGroup(r)
	,Entity(){
}

ImageEntity::~ImageEntity(){
}

void ImageEntity::onCollide(SDLEngine::Entity *e){
	ImageEntity *i = dynamic_cast<ImageEntity*>(e);
	std::cout << i->count() << std::endl;
}

void ImageEntity::setX(float x){
	ImageGroup::x = x;
	Entity::x = x;
	Entity::w = ImageGroup::w;
}

void ImageEntity::setY(float y){
	ImageGroup::y = y;
	Entity::y = y;
	Entity::h = ImageGroup::h;
}

float ImageEntity::getX(){
	return ImageGroup::x;
}

float ImageEntity::getY(){
	return ImageGroup::y;
}
