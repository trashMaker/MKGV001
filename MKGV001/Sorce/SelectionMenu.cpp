#include "SelectionMenu.h"
#include "DxLib.h"
#include "OutputLog.h"
#include "Exception.h"
/**
* \namespace MKGV001
*/
namespace MKGV001{
	SelectionMenu::SelectionMenu(){
		cursor = 0;
	}
	SelectionMenu::~SelectionMenu(){

	}
	/**
	 * 新しい項目の追加
	 */
	void SelectionMenu::add(int x,int y,std::string str,int color){

		Data data;
		data.x = x;
		data.y = y;
		data.color = color;
		data.str = str;

		menuList.push_back(data);
	}
	void SelectionMenu::draw(){
		for (auto t : menuList){
			DrawString(t.x, t.y, t.str.c_str(), t.color);
		}
	}
	/**
	 * キーが押されたら判断
	 */
	void SelectionMenu::numCursor(int addNum){
		int temp = cursor + addNum;

		if (temp >= 0 && temp < menuList.size()){
			cursor += addNum;
		}

	}
	/**
	 * 現在指しているカーソルの描画
	 */
	void SelectionMenu::drawCursor(){
		
		int color = GetColor(255,255,255);

		auto check = [](int cursor, int size){	
			return (cursor < size) ? true : false;
		};

		bool flag = check(cursor, menuList.size());

		FLAGGED_OUTPUT(flag, "カーソルが指している位置は正常です", "カーソルが指している位置は異常です");
		if (!flag)THROW_EXCEPTION("カーソルは存在しないメニューを指しています");
		int difference = 30;
		DrawString(menuList[cursor].x - difference, menuList[cursor].y, "●", color);
	}
	int SelectionMenu::getCursor(){
		return cursor;
	}
}