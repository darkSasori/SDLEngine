#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "Headers.h"
#include "Rect.h"

NS_BEGIN

class Entity : public Rect{
	private:
		std::map<String, String> m_Prop;
		bool m_Collide;

	public:
		Entity();
		virtual ~Entity();

		virtual void onCollide(Entity *) = 0;

		void setProperty(String, String);
		String getProperty(String);

		virtual void checkCollide(Entity *);

		bool operator == (const Entity *);
		bool operator != (const Entity *);

		void setCollide(bool);
		bool getCollide();
};

NS_END

#endif
