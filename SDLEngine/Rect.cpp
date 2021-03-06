#include "Rect.h"

NS_BEGIN

Rect::Rect()
:x(0.0f)
,y(0.0f)
,w(0.0f)
,h(0.0f){
}

Rect::Rect(float fx, float fy, float fw, float fh)
:x(fx)
,y(fy)
,w(fw)
,h(fh){
}

Rect::~Rect(){
}

Rect Rect::operator = (Rect r){
	x = r.x;
	y = r.y;
	w = r.w;
	h = r.h;
}

NS_END
