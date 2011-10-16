#ifndef __SIZE_H__
#define __SIZE_H__

#include "Headers.h"

NS_BEGIN

class Size {
	private:
		int width;
		int height;

	public:
		Size();
		Size(int, int);
		~Size();

		void setWidth(int);
		void setHeight(int);

		int getWidth();
		int getHeight();
};

NS_END

#endif
