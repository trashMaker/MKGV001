/**
 * \file Exception
 * \brief 例外エラー情報を扱う
 */
#include <string>
#include <exception>
/**
 * \namespace MKGV001
 */
namespace MKGV001{
	/**
	 * \def
	 * 列行関数などはマクロ埋め込みで取得
	 */
#define THROW_EXCEPTION(MESSAGE)\
	throw MKGV001::Exception(MESSAGE,__FILE__,__FUNCTION__,__LINE__)
	/**
	 * 例外エラー情報を扱う
	 */
	class Exception :public std::exception{
	public:
		Exception(std::string message, std::string file, std::string function, int line);///<エラー情報を格納
		~Exception(){};

		virtual const char* what()const throw(); ///<メッセージを返す

		static void outputCout(const char* message); ///<コンソール用出力	
		static void outputMessageBox(const char* message); ///<メッセージボックス用出力

	private:
		std::string detailMessage; ///<出力用にまとめたエラー情報
	};
}