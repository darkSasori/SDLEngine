#ifndef __TESTTHREAD_H__
#define __TESTTHREAD_H__

#include "SDLEngine.h"

class TestThread : public SDLEngine::Thread {
	public:
		void work(){
			for( int i = 0; i < 50000000; i++ ){
				std::cout << i << "\r";
				sleep(1);
			}
		}	
};

#endif
