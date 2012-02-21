#include "Entity.h"

NS_BEGIN

Entity::Entity()
	:m_Collide(true){
}

Entity::~Entity(){
}

void Entity::setProperty(String name, String value){
	m_Prop[name] = value;
}

String Entity::getProperty(String name){
	return m_Prop[name];
}

void Entity::checkCollide(Entity *e){
	if( e == this )
		return;

	bool collide = false;
	/*
	std::cout << "1.1: " << x+w << " 1.2: " << e->x
		<< " 2.1: " << y+h << " 2.2: " << e->y
		<< " 3.1: " << y << " 3.2: " << e->y+e->h << std::endl;
	//*/


	if( (x+w) >= e->x &&
	    (y+h) >= e->y &&
	    y <= (e->y+e->h) &&
	    x <= (e->x+e->w) )
		collide = true;

	if( collide ){
		this->onCollide(e);
		e->onCollide(this);
	}
}

bool Entity::operator == (const Entity *e){
	return ((e->x == x) &&
		(e->y == y) &&
		(e->w == w) &&
		(e->h == h));
}

bool Entity::operator != (const Entity *e){
	return !((e->x == x) &&
		(e->y == y) &&
		(e->w == w) &&
		(e->h == h));
}

void Entity::setCollide(bool c){
	m_Collide = c;
}

bool Entity::getCollide(){
	return  m_Collide;
}

NS_END
