/** \file
 * メニュー項目を操作
 */
#include <vector>
#include <string>
/**
* \namespace MKGV001
*/
namespace MKGV001{
	/**
	 * メニュー項目を操作
	 */
	class SelectionMenu{
	public:
		SelectionMenu();
		~SelectionMenu();
		void add(int x, int y, std::string str, int color);///<新しい項目の追加
		void draw();///<menuList全データを描画
		void numCursor(int num);///<キーが押されたら判断
		void drawCursor();//現在指しているカーソルの描画
		int getCursor();
	private:

		struct Data{//描画時に必要なデータ群
			std::string str;
			int x;
			int y;
			int color;
		};
		std::vector<Data> menuList;//追加されたメニュー用描画データ
		int cursor;//現在指してるデータ
		
	};
}