#include "Framework.h"
#include "DxLib.h"
#include "SceneManager.h"
#include "OutputLog.h"
#include "Exception.h"
/**
 * \namespace MKGV001
 */
namespace MKGV001{
	
	/**
	 * プログラム終了前の後片付け
	 */
	Framework::~Framework(){
		
	/*	if (sceneManager){ 
			delete sceneManager;
			sceneManager = nullptr;
		}	*/
	}

	/**
	 * シングルトン
	 */
	Framework& Framework::getInstance(){
		static Framework framework;
		return framework;
	}
	/**
	 * ゲーム開始前の各種設定
	 */
	void Framework::init(){

		setWindow(1280, 720, 32, true);
		initDxlib();
		createGame();
		
	}
	/**
	 * ゲーム終了前の各種設定
	 */
	void Framework::end(){
		endDxLib();
	}
	/**
	 * ゲーム全体の管理をしているupdateを呼び出し
	 */
	void Framework::main(){
		sceneManager->update();
	}
	/**
	 * 終了時にendDxLibを呼ばないと異常終了する
	 */
	void Framework::initDxlib(){

		int init = DxLib_Init();

		auto checkMode = [](int mode){
			return (mode == 0) ? true : false;
		};

		bool flag = checkMode(init);

		FLAGGED_OUTPUT(flag, "DXlibの初期化に成功しました", "DXlibの初期化に失敗しました");
		if (!flag)THROW_EXCEPTION("DXlibの初期化に失敗しました");
	}
	/**
	 * 開始時にinitDxlibを呼ばないと異常終了する
	 */
	void Framework::endDxLib(){

		int end = DxLib_End();

		auto check = [](int mode){
			return (mode == 0) ? true : false;
		};

		bool flag = check(end);
		
		FLAGGED_OUTPUT(flag, "DXlibの終了に成功しました", "DXlibの終了に失敗しました");
		if (!flag)THROW_EXCEPTION("DXlibの終了に失敗しました");
	}
	/**
	 * ウィンドウの設定
	 * @breaf ウィンドウのサイズとモードの設定 
	 * @param width ウィンドウ幅
	 * @param height ウィンドウ高
	 * @param colorBitNum ウィンドウカラービット数
	 * @param windowMode TRUE:windowMode FALSE:fullScreenMode
	 * @return bool
	 * @sa init()
	 * @detail 
	 */
	void Framework::setWindow(int width, int height, int colorBitNum, bool windowMode){

		int window = ChangeWindowMode(windowMode);

		int graph = SetGraphMode(width, height, colorBitNum);

		auto check = [](int mode){
			return (mode == DX_CHANGESCREEN_OK) ? true : false;
		};

		bool flag = (check(window) && check(graph)) == true;

		FLAGGED_OUTPUT(flag, "ウィンドウの設定成功", "ウィンドウの設定失敗");
		if (!flag)THROW_EXCEPTION("ウィンドウの設定失敗");
	}
	/**
	 * ゲームの処理に移行
	 */
	void Framework::createGame(){
		sceneManager = new SceneManager();
	}
}