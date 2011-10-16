#ifndef __VIDEOMANAGER_H__
#define __VIDEOMANAGER_H__

#include "Headers.h"
#include "Exception.h"
#include "Size.h"

NS_BEGIN

class VideoManager {
	private:
		friend class Factory;
		String m_Title;
		Size m_Size;
		bool m_bFullScreen;
		Uint32 m_Tick;
		Uint32 m_Time;
		Uint32 m_Start;
		int m_Fps;

		VideoManager();
		void processTime();

	public:
		virtual ~VideoManager();

		void init();
		void createWindow(String, Size, bool);

		void setTime(Uint32);
		Uint32 getTime();
		float getTick();

		void beginDraw();
		void endDraw();
};

NS_END

#endif
