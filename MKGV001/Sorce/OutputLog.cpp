#include "OutputLog.h"
#include <fstream>
#include <boost/filesystem/path.hpp>
/**
 * \namespace MKGV001
 */
namespace MKGV001{
	/**
	 * 書き込み先のファイルを開く
	 */
	OutPutLog::OutPutLog() :outputFile(new std::ofstream("../MKGV001Log.txt", std::ios_base::out)){
		//outputFile = new std::ofstream("../MKGV001Log.txt", std::ios_base::out);
		logNumber = 0;
	}
	/**
	 * ファイルを閉じる
	 */
	OutPutLog::~OutPutLog(){
		outputFile->close(); //閉じる
	}
	/**
	 * ファイル名拡張子付きで取得
	 */
	std::string OutPutLog::getFileName(std::string file){
		boost::filesystem::path path(file);
		boost::filesystem::path fileName = path.filename();

		return fileName.string();
	}
	/**
 	 * ログの操作はプログラムの最初と最後だけでいいのでシングルトン
	 */
	OutPutLog& OutPutLog::getInstance(){
		static OutPutLog output;
		return output;
	}
	/**
	 * エラー情報を出力用に整理する
	 * \param condition flag
	 * \param successMessage 成功時のメッセ
	 * \param failMessage　失敗時のメッセ
	 * \param file エラーが起きたファイル名
	 * \param function エラーが起きた関数名
	 * \param line エラーが起きた行
	 */
	void OutPutLog::setData(bool condition, std::string successMessage, std::string failMessage, std::string file, std::string function, int line){
		
		//file名のみに短縮　　D/Source/test.cpp →　test
		std::string miniFileName = getFileName(file);

		if (condition){
			output(STRING("true"), condition, successMessage, miniFileName, function, line);
		}
		else{
			output(STRING("false"), condition, failMessage, miniFileName, function, line);
		}
	}
	/**
	* 出力用に整理する
	* \param message　メッセ
	* \param file OUTPUTが呼ばれたファイル名
	* \param function OUTPUTが呼ばれた関数名
	* \param line OUTPUTが呼ばれた行
	*/
	void OutPutLog::setData(std::string message, std::string file, std::string function, int line){

		//file名のみに短縮　　D/Source/test.cpp →　test
		std::string miniFileName = getFileName(file);

		output(message, miniFileName, function, line);
	}
	/**
	 * ログ情報として出力
	 * \param flagName flagの名前
	 * \param condition flag
	 * \param message　メッセ
	 * \param file エラーが起きたファイル名
	 * \param function エラーが起きた関数名
	 * \param line エラーが起きた行
	 */
	void OutPutLog::output(std::string flagName, bool condition, std::string message, std::string file, std::string function, int line){
		
		*outputFile << logNumber++ << ": ";
		*outputFile << flagName;
		*outputFile << "(" << condition << "):	";
		*outputFile << message << "	";
		*outputFile << "関数:" << function << "	";
		*outputFile << "行" << line;
		*outputFile << ":" << file;
		*outputFile << std::endl;
	}
	/**
	* ログ情報として出力
	* \param message　メッセ
	* \param file OUTPUTが呼ばれたファイル名
	* \param function OUTPUTが呼ばれた関数名
	* \param line OUTPUTが呼ばれた行
	*/
	void OutPutLog::output(std::string message, std::string file, std::string function, int line){

		*outputFile << logNumber++ << ": ";
		*outputFile << message << "	";
		*outputFile << "関数:" << function << "	";
		*outputFile << "行" << line;
		*outputFile << ":" << file;
		*outputFile << std::endl;
	}
}