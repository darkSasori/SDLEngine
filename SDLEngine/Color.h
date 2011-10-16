#ifndef __COLOR_H__
#define __COLOR_H__

#include "Headers.h"

NS_BEGIN

class Color {
	public:
		int r, g, b;

		Color();
		Color(int, int, int);
		virtual ~Color();
};

NS_END

#endif
