#include "TitleScene.h"
#include "Base.h"
#include "DxLib.h"
/**
 * \namespace MKGV001
 */
namespace MKGV001{

	TitleScene::TitleScene(){
		loadImage();
	}
	TitleScene::~TitleScene()
	{}
	/*
	 * 基底から呼び出す
	 */
	void TitleScene::draw(){
		drawImage(0, 0, getVariableID(BACKGROUND,image), true);
	}
	void TitleScene::update(){
	
	}
	/*
	 * 基底から呼び出す
	 */
	void TitleScene::loadImage(){
		appendID(BACKGROUND, LoadGraph("res/Title/Background.png"),&image);
	}
	/*
	 * 現在の実行中のフローを返して比較する
	 */
	int TitleScene::getCurrentScene()const{
		return SceneFlow::TITLE;
	}
}
