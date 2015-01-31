#include "KeyPushed.h"
#include "DxLib.h"
/**
 * \namespace MKGV001
 */
namespace MKGV001{

	bool KeyPushed::nowKeysPushed[256] = {false};
	bool KeyPushed::prevKeysPushed[256] = {false};
	char KeyPushed::keyState[256] = { NULL};

	KeyPushed::KeyPushed(){
		init();
	}
	KeyPushed::~KeyPushed(){

	}

	void KeyPushed::init(){
		for (int i = 0; i < 256; ++i){
			nowKeysPushed[i] = false;
			prevKeysPushed[i] = false;
		}
	}
	/**
	* キー取得　フレーム単位で取得
	*/
	void KeyPushed::update(){
		GetHitKeyStateAll(keyState);
	}
	/**
	* 押されてるかどうか
	*/
	bool KeyPushed::getKeyState(int keyCode){
		return (keyState[keyCode] == 1)? true:false;
	}
	/**
	* 前回と同じキーが押されているかチェック
	* TODO:あとで確認
	*/
	bool KeyPushed::checkKeyPushed(int keyCode){
		prevKeysPushed[keyCode] = nowKeysPushed[keyCode];

		nowKeysPushed[keyCode] = (keyState[keyCode] == 1)? true : false;

		if (nowKeysPushed[keyCode] && !prevKeysPushed[keyCode]) return true;
		else return false;
	}
	/**
	* 
	*/
	KeyPushed& KeyPushed::getInstance(){
		static KeyPushed keyPushed;
		return keyPushed;
	}
}