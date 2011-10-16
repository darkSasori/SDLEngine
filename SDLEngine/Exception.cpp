#include "Exception.h"

NS_BEGIN

Exception::Exception(char *format, ...){
	char buff[1024];
	va_list args;

	va_start(args, format);
	vsnprintf(buff, 1024, format, args);
	va_end(args);

	m_Message = buff;
}


Exception::~Exception(){
}

const char* Exception::what(){
	return m_Message.c_str();
}

NS_END
