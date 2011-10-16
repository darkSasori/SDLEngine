#ifndef __LIST_H__
#define __LIST_H__

#include "Headers.h"

NS_BEGIN

template<typename t>
class List : public std::list<t> {
	public:
		void operator += (const t& e){
			push_back(e);
		}

		void operator -= (const t& e){
			typename std::list<t>::iterator i = std::find(this->begin(), this->end(), e);
			if( i != this->end() )
				this->erase(i);
		}
};

NS_END

#endif
