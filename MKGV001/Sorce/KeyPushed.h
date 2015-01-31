/** \file
 * キー操作
 */
#include <vector>
/**
 * \namespace MKGV001
 */
namespace MKGV001{
	/**
	 * キー操作
	 */
	class KeyPushed{

	public:
		
		~KeyPushed();

		void init();///<
		void update();///<キー取得　フレーム単位で取得
		bool checkKeyPushed(int keyCode);///<前回と同じキーが押されているかチェック
		bool getKeyState(int keyCode);///<押されてるかどうか

		static KeyPushed& getInstance();///<
	private:

		static bool nowKeysPushed[256];///<キー入力に使用
		static bool prevKeysPushed[256];///<キー入力に使用
		static char keyState[256];///<現在フレームで取得したキー配列

		KeyPushed();
		KeyPushed(const KeyPushed& obj){};
		KeyPushed& operator=(const KeyPushed& obj){};
		
	};
	static KeyPushed& key = KeyPushed::getInstance();///<ここでオブジェクトを作成しておく
}