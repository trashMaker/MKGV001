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
	* �L�[�擾�@�t���[���P�ʂŎ擾
	*/
	void KeyPushed::update(){
		GetHitKeyStateAll(keyState);
	}
	/**
	* ������Ă邩�ǂ���
	*/
	bool KeyPushed::getKeyState(int keyCode){
		return (keyState[keyCode] == 1)? true:false;
	}
	/**
	* �O��Ɠ����L�[��������Ă��邩�`�F�b�N
	* TODO:���ƂŊm�F
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