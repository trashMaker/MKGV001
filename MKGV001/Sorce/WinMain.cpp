/**\file WinMain
 * \brief プログラムの開始
 */
#include "DxLib.h"
#include "Framework.h"
#include "Exception.h"
#include "OutputLog.h"
/**
 * プログラムの全体実行処理
 * \breaf Dxライブラリやゲーム開始を実行　
 * \sa frame->init()
 */

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){


	try{
		MKGV001::framework.init();
		MKGV001::framework.main();
	}
	catch (std::exception& ex){
		
		MKGV001::Exception::outputMessageBox(ex.what());
	}

	MKGV001::framework.end();

	return 0;				///< ソフトの終了 
}