#ifndef __ENTITY_H__
#define __ENTITY_H__

#include "Headers.h"
#include "Rect.h"

NS_BEGIN

class Entity : public Rect{
	protected:
		bool m_bCollide;
		int m_Id;

	public:
		virtual void onCollide() = 0;

		void setCollide(bool);
		bool getCollide();

		bool operator == (const Entity *);
};

NS_END

#endif
