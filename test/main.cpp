#include "SDLEngine.h"
#include "ImageEntity.h"

using SDLEngine::List;
using SDLEngine::Size;
using SDLEngine::Rect;
using SDLEngine::Color;
using SDLEngine::Image;
using SDLEngine::ImageGroup;

class Main : public SDLEngine::Application, SDLEngine::EventListener {
	private:
		bool bRun;
		ImageEntity *grp;
		ImageEntity *img;

	public:
		int main(List<String> args){
			while( bRun ){
				factory->getVideoManager()->beginDraw();
				factory->getEventManager()->process();

				grp->draw();
				img->draw();

				//printf("FPS: %0.00f\r", factory->getVideoManager()->getTick());
				factory->getVideoManager()->endDraw();
			}
			return 0;
		}

		void init(){
			int k[] = {SDLK_a, SDL_BUTTON_LEFT};
			bRun = true;

			factory->getVideoManager()->init();
			factory->getVideoManager()->createWindow("Teste", Size(800,600), false);

			factory->getEventManager()->init();
			factory->getEventManager()->addEventListener(SDL_QUIT, 1, this);
			factory->getEventManager()->addEventListener(SDLK_q, 1, this);
			factory->getEventManager()->addEventListener(SDLK_UP, 2, this);
			factory->getEventManager()->addEventListener(SDLK_DOWN, 3, this);
			factory->getEventManager()->addEventListener(SDLK_LEFT, 4, this);
			factory->getEventManager()->addEventListener(SDLK_RIGHT, 5, this);

			img = new ImageEntity(true);
			img->addImage( Image::createImage(Rect(90,10,45,45), Color(255,255,255)) );
			img->setX(150);
			img->setY(150);
			img->begin();

			grp = new ImageEntity(true);
			grp->addImage( Image::createImage(Rect(90,10,45,45), Color(0,0,0)) );
			grp->addImage( Image::createImage(Rect(90,10,45,45), Color(255,0,0)) );
			grp->addImage( Image::createImage(Rect(90,10,45,45), Color(0,255,0)) );
			grp->addImage( Image::createImage(Rect(90,10,45,45), Color(0,0,255)) );
			grp->addImage( Image::createImage(Rect(90,10,45,45), Color(255,255,255)) );
			grp->setX(100);
			grp->setY(100);
			grp->begin();

			factory->getEntityManager()->addEntity(grp);
			factory->getEntityManager()->addEntity(img);
		}

		void treat(SDLEngine::Event e){
			switch( e.id ){
			case 1:
				bRun = false;
				break;
			case 2: grp->setY(grp->getY() - 2); factory->getEntityManager()->collid(grp); break;
			case 3: grp->setY(grp->getY() + 2); factory->getEntityManager()->collid(grp); break;
			case 4: grp->setX(grp->getX() - 2); factory->getEntityManager()->collid(grp); break;
			case 5: grp->setX(grp->getX() + 2); factory->getEntityManager()->collid(grp); break;
			}
		}
}app;
