#ifndef __IMAGEGROUP_H__
#define __IMAGEGROUP_H__

#include "Headers.h"
#include "Image.h"
#include "Rect.h"

NS_BEGIN

class ImageGroup : public Rect {
	private:
		vector<Image*> m_Images;
		vector<Image*>::iterator m_It;
		bool m_bRepeat;
		int i;

	public:
		float rotation;

		ImageGroup(bool);
		virtual ~ImageGroup();

		void setRepeat(bool);
		bool getRepeat();

		void addImage(Image*);
		void removeImage(Image*);

		void begin();

		void draw();
};

NS_END

#endif
