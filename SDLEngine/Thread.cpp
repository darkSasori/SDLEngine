#include "Thread.h"

NS_BEGIN

Thread::Thread()
	:m_bStart(false){
}

Thread::~Thread(){
}

void Thread::start(){
	m_Thread =  boost::thread(&Thread::work, this);
}

void Thread::wait(){
	m_Thread.join();
}

void Thread::lock(){
	m_Lock = boost::mutex::scoped_lock(m_Mutex);
}

void Thread::unlock(){
	m_Lock.unlock();
}

NS_END
