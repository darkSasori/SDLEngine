#ifndef __LIST_H__
#define __LIST_H__

#include "Headers.h"

NS_BEGIN

template<typename t>
class Vector : public std::vector<t> {
	public:
		void operator += (const t& e){
			push_back(e);
		}

		void operator -= (const t& e){
			typename std::vector<t>::iterator i = std::find(this->begin(), this->end(), e);
			if( i != this->end() )
				this->erase(i);
		}
};

NS_END

#endif
