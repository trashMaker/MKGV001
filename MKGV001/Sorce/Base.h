/**
 * \file Base
 * \brief 各種クラスから使用頻度の高い関数群
 */
#include <map>
#include "DxLib.h"
#include "Exception.h"
/**
 * \namespace MKGV001
 */
namespace MKGV001{
	/*
	 * keyIDをキーとしたvariableID保持する
	 * \param keyID キーID
	 * \param variableID キーIDと関連付けられたデータ
	 * \param mapName 入れるmapの名前
	 */
	template<class TYPEKEY, class TYPE>
	void appendID(TYPEKEY keyID, TYPE variableID, std::map<TYPEKEY, TYPE>* mapName){
		//graphicsIDを画像へのハンドルのキーとして登録しつつ画像もmap配列に格納
		mapName->insert(std::pair<TYPEKEY, TYPE>(keyID, variableID));
	}
	/*
	 * keyIDに関連付けられたデータを返す
	 * \param keyID キーID
	 * \param mapName 取り出すmapの名前
	 * \return 関連付けられたデータ
	 */
	template<class TYPEKEY, class TYPE>
	TYPE getVariableID(TYPEKEY keyID, std::map<TYPEKEY, TYPE>& mapName){
		std::map<TYPEKEY, TYPE>::iterator p;
		//キーIDと合うものを検索
		p = mapName.find(keyID);
		//あれば
		if (p != mapName.end()){
			//キーIDに関連付けられたデータを返す
			return p->second;
		}
		//無ければ
		THROW_EXCEPTION("keyIDに対応する画像が存在しません");
	}
	/*
	* Dxライブラリの画像のラッパ
	* \param keyID キーID
	* \param mapName 取り出すmapの名前
	* \return 関連付けられたデータ
	*/
	void drawImage(int x, int y, int grHandle, bool transFlag){
		DrawGraph(x, y, grHandle, transFlag);
	}
}