#include "Factory.h"

NS_BEGIN

Factory *Factory::m_Factory = NULL;

Factory::Factory()
:m_VideoManager(NULL)
,m_EventManager(NULL)
,m_EntityManager(NULL){
}

Factory::~Factory(){
	Factory::m_Factory = NULL;
}

Factory *Factory::instance(){
	if( Factory::m_Factory == NULL )
		Factory::m_Factory = new Factory();
	return 	Factory::m_Factory;
}

VideoManager *Factory::getVideoManager(){
	if( m_VideoManager == NULL )
		m_VideoManager = new VideoManager();
	return m_VideoManager;
}

EventManager *Factory::getEventManager(){
	if( m_EventManager == NULL )
		m_EventManager = new EventManager();
	return m_EventManager;
}

EntityManager *Factory::getEntityManager(){
	if( m_EntityManager == NULL )
		m_EntityManager = new EntityManager();
	return m_EntityManager;
}

NS_END
