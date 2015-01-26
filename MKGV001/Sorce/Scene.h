/**\file Scene
 * インターフェイス
 */
#pragma once
/**
* \namespace MKGV001
*/
namespace MKGV001{
	/**
	* インターフェイス
	*/
	class Scene{
	public:
		virtual ~Scene() = 0;///<デストラクタ
	
		virtual void update() = 0;///<更新
		
		virtual void draw() = 0;///<描画
		
		virtual void loadImage() = 0;///<画像読み込み

		virtual int getCurrentScene()const = 0;
	};
}