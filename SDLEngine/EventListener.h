#ifndef __EVENTLISTENER_H__
#define __EVENTLISTENER_H__

#include "Headers.h"
#include "Event.h"

NS_BEGIN

class EventListener {
	public:
		virtual void treat(Event) = 0;
};

NS_END

#endif
