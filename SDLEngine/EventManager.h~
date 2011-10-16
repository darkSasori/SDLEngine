#ifndef __EVENTMANAGER_H__
#define __EVENTMANAGER_H__

#include "Headers.h"
#include "Exception.h"
#include "EventListener.h"
#include "EventList.h"

NS_BEGIN

class EventManager {
	private:
		friend class Factory;
		vector<EventList*> m_Events;

		EventManager();

	public:
		virtual ~EventManager();

		void process();

		void init();
		// Event, id, classe ouvinte
		void addEventListener(int, int, EventListener*);
		void addEventListener(int[], int, EventListener*);
};

NS_END

#endif
