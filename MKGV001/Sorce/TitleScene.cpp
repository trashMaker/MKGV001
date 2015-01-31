#include "TitleScene.h"
#include "Base.h"
#include "DxLib.h"
#include <cstdarg>
#include <string>
#include "KeyPushed.h"
#include "SelectionMenu.h"
#include "TrainingScene.h"
/**
 * \namespace MKGV001
 */
namespace MKGV001{
	TitleScene::TitleScene(){
		loadImage();
		menu = new SelectionMenu();
		setMenu();
	}
	TitleScene::~TitleScene()
	{
		if (menu){
		delete menu;
		menu = nullptr;
		}
	}
	/**
	 * 基底から呼び出す
	 */
	void TitleScene::draw(){
		drawImage(0, 0, getVariableID(BACKGROUND,image), true);
		menu->draw();
		menu->drawCursor();
	}
	/**
	 * 基底から呼び出す
	 */
	Scene& TitleScene::update(){
		Scene* next = this;
		int cursorAddNumber = 1;

		if (key.checkKeyPushed(KEY_INPUT_UP) == true){
			menu->numCursor(-cursorAddNumber);
		}
		else if (key.checkKeyPushed(KEY_INPUT_DOWN) == true){
			menu->numCursor(cursorAddNumber);
		}
		else if(key.checkKeyPushed(KEY_INPUT_SPACE) == true){
			
			if (menu->getCursor() == 0){
				next = new TrainingScene();
			}
			
		}
		return *next;
	}
	/**
	 * 基底から呼び出す
	 */
	void TitleScene::loadImage(){
		appendID(BACKGROUND, LoadGraph("res/Title/Background.png"),&image);
	}
	/**
	 *  コンストラクタで呼び出す
	 */
	void TitleScene::setMenu(){
		int stringPositionX = 0;
		int stringPositionY = 0;
		std::string str = "スタート";
		
		setFistMenuPostion(&stringPositionX, &stringPositionY, str);

		int size = 30;
		menu->add(stringPositionX, stringPositionY, "スタート", GetColor(255, 255, 255));

		menu->add(stringPositionX, stringPositionY + size, "終了", GetColor(255, 255, 255));

	}
	/**
	* setMenuでメニューの描画開始位置の元にしたいので一度のみ呼び出す
	* \brief ウィンドウサイズなどからメニュー位置を取得している
	*/
	void TitleScene::setFistMenuPostion(int* posX, int* posY,std::string str){
		int windowWidth = 0;
		int windowHeight = 0;
		int ColorBitDepth = 0;

		GetScreenState(&windowWidth, &windowHeight, &ColorBitDepth);

		int strWidth = getStrWidth(str.c_str());

		*posX = (windowWidth / 2) - (strWidth / 2);
		*posY = windowHeight - windowHeight / 4;
	}
	/**
	* setMenuで位置をセットする時に使う
	*/
	int TitleScene::getStrWidth(const char* str){
		int StrLen = strlen(str);
		return  GetDrawStringWidth(str, StrLen);
	}
	//void TitleScene::drawMenuString(){
	//	int color = GetColor(255, 255, 255);
	//	int size = 30;
	//	setMenu(size, color, 3, "スタート", "メニュー", "終了");
	//}
	//void TitleScene::setMenu(int size, int color, int num,...){
	//	bool flag = false;

	//	int windowWidth = 0;
	//	int windowHeight = 0;
	//	int ColorBitDepth = 0;

	//	GetScreenState(&windowWidth, &windowHeight, &ColorBitDepth);

	//	int startXPosition = 0;
	//	int startYPosition = 0;

	//	std::string str;
	//	va_list data;
	//	va_start(data, num);
	//	for (int i = 0; i < num; ++i){
	//		str = va_arg(data, const char*);
	//		int strWidth = getStrWidth(str.c_str());
	//		if (flag ==false ){

	//			startXPosition = (windowWidth / 2) - (strWidth / 2);
	//			startYPosition = windowHeight - windowHeight / 4;
	//			flag = true;
	//		}
	//		DrawString(startXPosition, startYPosition + (i*size), str.c_str(), color);
	//	}
	//	va_end(data);
	//}
	
}
