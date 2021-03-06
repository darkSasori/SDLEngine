#include "ImageGroup.h"

NS_BEGIN

ImageGroup::ImageGroup(bool r)
:m_bRepeat(r)
,rotation(0.0f){
	Rect();
}

ImageGroup::~ImageGroup(){
}

void ImageGroup::setRepeat(bool r){
	m_bRepeat = r;
}

bool ImageGroup::getRepeat(){
	return m_bRepeat;
}

void ImageGroup::addImage(Image *img){
	img->x = x;
	img->y = y;
	w = img->w;
	h = img->h;
	m_Images.push_back(img);
}

int ImageGroup::count(){
	return (int)m_Images.size();
}

void ImageGroup::begin(){
	m_It = m_Images.begin();
}

void ImageGroup::draw(){
	if( m_It == m_Images.end() ){
		if( m_bRepeat )
			m_It = m_Images.begin();
		else
			return;
	}
	(*m_It)->x = x;
	(*m_It)->y = y;
	(*m_It)->draw();
	m_It++;
}

NS_END
