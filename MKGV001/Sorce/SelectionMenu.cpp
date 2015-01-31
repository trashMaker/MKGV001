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
	 * �V�������ڂ̒ǉ�
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
	 * �L�[�������ꂽ�画�f
	 */
	void SelectionMenu::numCursor(int addNum){
		int temp = cursor + addNum;

		if (temp >= 0 && temp < menuList.size()){
			cursor += addNum;
		}

	}
	/**
	 * ���ݎw���Ă���J�[�\���̕`��
	 */
	void SelectionMenu::drawCursor(){
		
		int color = GetColor(255,255,255);

		auto check = [](int cursor, int size){	
			return (cursor < size) ? true : false;
		};

		bool flag = check(cursor, menuList.size());

		FLAGGED_OUTPUT(flag, "�J�[�\�����w���Ă���ʒu�͐���ł�", "�J�[�\�����w���Ă���ʒu�ُ͈�ł�");
		if (!flag)THROW_EXCEPTION("�J�[�\���͑��݂��Ȃ����j���[���w���Ă��܂�");
		int difference = 30;
		DrawString(menuList[cursor].x - difference, menuList[cursor].y, "��", color);
	}
	int SelectionMenu::getCursor(){
		return cursor;
	}
}