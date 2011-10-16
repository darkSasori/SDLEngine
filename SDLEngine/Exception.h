#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include "Headers.h"

NS_BEGIN

class Exception{
	public:
		Exception(char *format, ...);
		~Exception();

		const char* what();

	private:
		String m_Message;
};

NS_END

#endif
