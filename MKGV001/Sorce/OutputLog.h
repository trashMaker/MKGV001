/**
* 外部ファイルにログを出力する
*/
#include <iostream>
#include <memory>
#include <string>
#include <fstream>
/*
 * \namespace MKGV001
 */
namespace MKGV001{

#define STRING(str)#str///<文字列連結

#ifdef _DEBUG///< デバック時
	/**
	* 列行関数などはマクロ埋め込みで取得
	* \param CONDITION 成功時失敗時の処理をわける時に使うflag
	* \param SUCCESSMESSAGE 成功時のメッセ
	* \param FAILMESSAGE 失敗時のメッセ
	*/
#define OUTPUT(CONDITION,SUCCESSMESSAGE,FAILMESSAGE)\
	MKGV001::outputLog.setData(CONDITION,SUCCESSMESSAGE,FAILMESSAGE,__FILE__,__FUNCTION__,__LINE__)

#else ///< #ifdef _DEBUG
	//リリース時
#define OUTPUT(CONDITION,SUCCESSMESSAGE,FAILMESSAGE)

#endif ///< #ifdef _DEBUG


	/**
	* 外部ファイルにログを出力する
	*/
	class OutPutLog{

	public:
		static OutPutLog& getInstance();///<staticオブジェクトを一度生成してそのオブジェクトへの参照

		void setData(bool condition, std::string successMessage, std::string failMessage, std::string file, std::string function, int line);///<出力用にデータを加工
		void output(std::string flagName, bool condition, std::string message, std::string file, std::string function, int line);///<外部ファイルにログ出力
		
	private:

		std::unique_ptr<std::ofstream> outputFile;///< uniqueptrで自動開放させる ファイル書き込み

		std::string getFileName(std::string file);///< __FILE__のディレクトリなどのファイル名を test.cppを抜き出す

		OutPutLog();
		OutPutLog(const OutPutLog& obj){};
		OutPutLog& operator=(const OutPutLog& obj){};
		~OutPutLog();

	};
	static OutPutLog& outputLog = OutPutLog::getInstance(); ///<ここで生成しておけば、生成場所の指定しなくてすむ


}