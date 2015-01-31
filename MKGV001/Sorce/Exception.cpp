#include "Exception.h"
#include <Windows.h>
#include <iostream>
#include <sstream>
namespace MKGV001{
	/**
	 * エラー情報を構築
	 * \param message エラーメッセージ
	 * \param file エラーが起きたファイル名
	 * \param function エラーが起きた関数名
	 * \param line エラーが起きた行番号
	 */
	Exception::Exception(std::string message, std::string file,std::string function, int line)
	{
		std::ostringstream osio;

		osio << file << "ファイルの" << std::endl;
		osio << function << "関数の" << std::endl;
		osio << line << "行目で" << std::endl;
		osio << message << std::endl;

		detailMessage = osio.str();
	}
	/**
	 * コンソールに表示
	 * \param メッセージ
	 */
	void Exception::outputCout(const char* message){
		std::cout << message;
	}
	/**
	 * メッセージボックスに表示
	 * \param メッセージ
	 */
	void Exception::outputMessageBox(const char* message){
	
		MessageBoxA(NULL, message,"例外エラー", MB_OK);
	}
	/**
	* メッセージを返す
	*/
	const char* Exception::what()const throw(){

		return detailMessage.c_str();
	}
}