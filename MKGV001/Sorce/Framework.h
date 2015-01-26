/** \file
 * ゲーム開始前枠組みの設定　シングルトン
 */
/**
 * \namespace MySpace
 */
namespace MKGV001{

	class SceneManager;
	/**
	* ゲーム開始前枠組みの設定　シングルトン
	*/
	class Framework{
	public:

		void init();///<ゲーム開始前の各種設定
		void end();///<ゲーム終了前の各種設定

		void main();///<ゲーム全体の開始

		static Framework& getInstance(); ///<初回オブジェクト生成　以後
	private:
		
		void createGame();///<ゲームフローの生成

		void initDxlib();///<DXライブラリ初期化

		void endDxLib();///<DXライブラリ終了処理
		
		void setWindow(int width, int height, int colorBitNum, bool windowMode);///<ウィンドウの設定

		SceneManager* sceneManager;///<ゲームの処理に移行

		Framework(){};///< シングルトンを作成のために実装は無し
		Framework(const Framework& obj){};
		Framework& operator=(const Framework& obj){};	
		~Framework();///<プログラム終了前の後片付け
	};
	//ここでオブジェクトを作成しておく
	static Framework& framework = Framework::getInstance();
}