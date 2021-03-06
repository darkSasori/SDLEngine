#ifndef __FACTORY_H__
#define __FACTORY_H__

#include "Headers.h"
#include "VideoManager.h"
#include "EventManager.h"
#include "EntityManager.h"

NS_BEGIN

class Factory {
	private:
		Factory();

		VideoManager *m_VideoManager;
		EventManager *m_EventManager;
		EntityManager *m_EntityManager;

	public:
		~Factory();

		static Factory *m_Factory;
		static Factory *instance();

		VideoManager *getVideoManager();
		EventManager *getEventManager();
		EntityManager *getEntityManager();
		
		void initVideoManager();

};

NS_END

#endif
