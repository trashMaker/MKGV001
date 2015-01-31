#include "SceneManager.h"
#include "TitleScene.h"
#include "TrainingScene.h"
#include "DxLib.h"
#include "OutputLog.h"
#include <vector>
#include "Fps.h"
#include "KeyPushed.h"
/**
 * \namespace MKGV001
 */
namespace MKGV001{
	/**
	 * タイトルが入る
	 */
	SceneManager::SceneManager(){
		currentScene = new TitleScene();
		fps = new Fps();
	}
	/**
	 * インターフェイス
	 */
	SceneManager::~SceneManager(){
		if (currentScene){
			delete currentScene;
			currentScene = nullptr;
		}
		if (fps){
			delete fps;
			fps = nullptr;
		}
	}
	/**
	 * 更新処理
	 */
	void SceneManager::update(){

		while (ProcessMessage() == 0){

			fps->updateSeGaVer();

			key.update();
			Scene* nextScene = currentScene->update();
			currentScene->draw();

			fps->waitSeGaVer();
			fps->drawFpsSeGaVer();
			
			if (ProcessMessage() == -1){
				OUTPUT("エラー終了もしくは、ウィンドウが閉じられました");
			}
		}
	}
	/**
	 * 現在のフローを変更
	 * \param flow 変更するフロー
	 */
	void SceneManager::changeScene(const Scene& scene){

		if (currentScene != &scene){
			delete currentScene;
			currentScene = nullptr;

			switch (scene.getCurrentScene()){
			case TitleScene::SceneFlow::TITLE:
				currentScene = &scene;
				break;
			}
		}
	}
}