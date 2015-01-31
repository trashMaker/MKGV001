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
	
	class SelectionMenu;
	/**
	* タイトルシーン
	*/
	class TitleScene : public Scene{
	public:
		TitleScene();

		~TitleScene();

		Scene& update();

		void draw();

		void loadImage();

		enum NextScene{
			NEXT_GAME,
			NEXT_
		};

		int getCurrentScene()const;///<SceneFlow::TITLEを返す
	
	private:

		SelectionMenu* menu;
		void setMenu();///<選択する項目を作成
		
		int getStrWidth(const char* str);///<描画位置を決めるのに使う
		void setFistMenuPostion(int* posX, int* posY, std::string str);///<描画開始位置をウィンドウから取得

		enum IMAGEID{///<画像を取得するID
			BACKGROUND
		};
		std::map<IMAGEID, int> image;///<画像はgetVariableIDを使って取り出す
	};
}