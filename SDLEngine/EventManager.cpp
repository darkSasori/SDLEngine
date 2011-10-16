#include "EventManager.h"

NS_BEGIN

EventManager::EventManager(){
}

EventManager::~EventManager(){
}

void EventManager::init(){
	SDL_EnableUNICODE(SDL_ENABLE);
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
}

void EventManager::addEventListener(int events, int id, EventListener *list){
	m_Events.push_back(new EventList(events, id, list));
}

void EventManager::addEventListener(int events[], int id, EventListener *list){
	m_Events.push_back(new EventList(events, id, list));
}

void EventManager::process(){
	SDL_Event e;
	Uint8 *k = SDL_GetKeyState(NULL);
	vector<SDL_Event> events;
	while( SDL_PollEvent(&e) ){
		events.push_back(e);
	}
	
	vector<EventList*>::iterator it;
	for( it = m_Events.begin(); it != m_Events.end(); it++ ){
		(*it)->verify(events, k);
	}
}

NS_END
