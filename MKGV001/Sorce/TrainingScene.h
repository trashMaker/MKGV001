/**
* \file Training
* \brief 育成パート
*/
#include "Scene.h"
#include <map>
#include "SelectionMenu.h"
namespace MKGV001{
	class TrainingScene :public Scene{
	public:
		TrainingScene();
		~TrainingScene();
		Scene& update();

		void draw();

		void loadImage();
	private:
		enum IMAGEID{
			
		};
		std::map<IMAGEID, int> image;
		SelectionMenu* menu;
	};
}