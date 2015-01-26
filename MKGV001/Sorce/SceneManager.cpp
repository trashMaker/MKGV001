#include "SceneManager.h"
#include "TitleScene.h"
#include "DxLib.h"
#include "OutputLog.h"
/**
 * \namespace MKGV001
 */
namespace MKGV001{
	/**
	 * タイトルが入る
	 */
	SceneManager::SceneManager(){
		currentScene = new TitleScene();
	}
	/**
	 * インターフェイス
	 */
	SceneManager::~SceneManager(){
		if (currentScene){
			delete currentScene;
			currentScene = nullptr;
		}
	}
	/**
	 * 更新処理
	 */
	void SceneManager::update(){

		while (1){
			currentScene->draw();

			if (ProcessMessage() == -1){
				
				//OUTPUT(false, "エラーもしくは、ウィンドウが閉じられました");
				break;
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

			/*switch (scene.getCurrentScene()){
			case TitleScene::SceneFlow::TITLE:
				currentScene = new TitleScene();
				break;
			}*/
		}
	}
}