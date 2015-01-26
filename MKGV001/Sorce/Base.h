/**
 * \file Base
 * \brief �e��N���X����g�p�p�x�̍����֐��Q
 */
#include <map>
#include "DxLib.h"
#include "Exception.h"
/**
 * \namespace MKGV001
 */
namespace MKGV001{
	/*
	 * keyID���L�[�Ƃ���variableID�ێ�����
	 * \param keyID �L�[ID
	 * \param variableID �L�[ID�Ɗ֘A�t����ꂽ�f�[�^
	 * \param mapName �����map�̖��O
	 */
	template<class TYPEKEY, class TYPE>
	void appendID(TYPEKEY keyID, TYPE variableID, std::map<TYPEKEY, TYPE>* mapName){
		//graphicsID���摜�ւ̃n���h���̃L�[�Ƃ��ēo�^���摜��map�z��Ɋi�[
		mapName->insert(std::pair<TYPEKEY, TYPE>(keyID, variableID));
	}
	/*
	 * keyID�Ɋ֘A�t����ꂽ�f�[�^��Ԃ�
	 * \param keyID �L�[ID
	 * \param mapName ���o��map�̖��O
	 * \return �֘A�t����ꂽ�f�[�^
	 */
	template<class TYPEKEY, class TYPE>
	TYPE getVariableID(TYPEKEY keyID, std::map<TYPEKEY, TYPE>& mapName){
		std::map<TYPEKEY, TYPE>::iterator p;
		//�L�[ID�ƍ������̂�����
		p = mapName.find(keyID);
		//�����
		if (p != mapName.end()){
			//�L�[ID�Ɋ֘A�t����ꂽ�f�[�^��Ԃ�
			return p->second;
		}
		//�������
		THROW_EXCEPTION("keyID�ɑΉ�����摜�����݂��܂���");
	}
	/*
	* Dx���C�u�����̉摜�̃��b�p
	* \param keyID �L�[ID
	* \param mapName ���o��map�̖��O
	* \return �֘A�t����ꂽ�f�[�^
	*/
	void drawImage(int x, int y, int grHandle, bool transFlag){
		DrawGraph(x, y, grHandle, transFlag);
	}
}