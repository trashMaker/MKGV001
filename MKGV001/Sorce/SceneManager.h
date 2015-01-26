/**
 * \file SceneManager
 * \brief Sceneの処理
 */
#include "Scene.h"
/**
 * \namespace MySpace
 */
namespace MKGV001{

	class TitleScene;
	/**
	 * SceneManager 
	 * \brief フローの処理
 	 */
	class SceneManager{
	public:
		SceneManager();
		~SceneManager();

		void update();
	private:
		
		void changeScene(const Scene& scene);///<フローを変える
		
		Scene* currentScene; ///<現在のフロー

	};
}