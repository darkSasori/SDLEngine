#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Headers.h"
#include "Exception.h"
#include "List.h"
#include "Factory.h"

NS_BEGIN

class Application {
	protected:
		Factory *factory;
	public:
		static Application *m_App;
		Application();
		virtual ~Application();

		virtual int main(List<String>) = 0;
		virtual void init() = 0;
		virtual void close();
};

NS_END

#endif
