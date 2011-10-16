#ifndef __MAP_H__
#define __MAP_H__

#include "Headers.h"

NS_BEGIN

template<typename t, typename c>
class Map : std::map<t, c>{
};

NS_END

#endif
