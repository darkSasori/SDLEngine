#ifndef __THREAD_H__
#define __THREAD_H__

#include "Headers.h"
#include <boost/bind.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>

NS_BEGIN

class Thread {
	private:
		bool m_bStart;
		boost::thread m_Thread;
		boost::mutex m_Mutex;
		boost::mutex::scoped_lock m_Lock;

	public:
		Thread();
		virtual ~Thread();

		void start();
		void stop();
		void wait();
		void lock();
		void unlock();

		virtual void work() = 0;
};

NS_END

#endif
