#include "Exception.h"
#include <Windows.h>
#include <iostream>
#include <sstream>
namespace MKGV001{
	/**
	 * �G���[�����\�z
	 * \param message �G���[���b�Z�[�W
	 * \param file �G���[���N�����t�@�C����
	 * \param function �G���[���N�����֐���
	 * \param line �G���[���N�����s�ԍ�
	 */
	Exception::Exception(std::string message, std::string file,std::string function, int line)
	{
		std::ostringstream osio;

		osio << file << "�t�@�C����" << std::endl;
		osio << function << "�֐���" << std::endl;
		osio << line << "�s�ڂ�" << std::endl;
		osio << message << std::endl;

		detailMessage = osio.str();
	}
	/**
	 * �R���\�[���ɕ\��
	 * \param ���b�Z�[�W
	 */
	void Exception::outputCout(const char* message){
		std::cout << message;
	}
	/**
	 * ���b�Z�[�W�{�b�N�X�ɕ\��
	 * \param ���b�Z�[�W
	 */
	void Exception::outputMessageBox(const char* message){
	
		MessageBoxA(NULL, message,"��O�G���[", MB_OK);
	}
	/**
	* ���b�Z�[�W��Ԃ�
	*/
	const char* Exception::what()const throw(){

		return detailMessage.c_str();
	}
}