/**
 * \file Title
 * \brief タイトル
 */
#include "Scene.h"
#include <map>
/**
 * \namespace MySpace
 */
namespace MKGV001{
	/**
	 * タイトルシーン
	 */
	class TitleScene : public Scene{
	public:
		TitleScene();

		~TitleScene();

		void update(); 

		void draw(); 

		void loadImage();

		enum SceneFlow{ ///<SceneManagerで比較して新しくnewする時に使うのでpublic
			TITLE
		};

		int getCurrentScene()const; ///<SceneFlow::TITLEを返す
	
	private:
		enum IMAGEID{///<画像を取得するID
			BACKGROUND
		};
		std::map<IMAGEID, int> image;///<画像はgetVariableIDを使って取り出す
	};
}