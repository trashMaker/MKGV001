#include "TrainingScene.h"
#include "SelectionMenu.h"
namespace MKGV001{
	TrainingScene::TrainingScene(){
		menu = new SelectionMenu();
	}
	TrainingScene::~TrainingScene(){
		if (menu){
			delete menu;
			menu = nullptr;
		}
	}
	Scene& TrainingScene::update(){
		
	}
	void TrainingScene::draw(){

	}
	void TrainingScene::loadImage(){

	}
}