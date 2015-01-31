/** \file
 * �L�[����
 */
#include <vector>
/**
 * \namespace MKGV001
 */
namespace MKGV001{
	/**
	 * �L�[����
	 */
	class KeyPushed{

	public:
		
		~KeyPushed();

		void init();///<
		void update();///<�L�[�擾�@�t���[���P�ʂŎ擾
		bool checkKeyPushed(int keyCode);///<�O��Ɠ����L�[��������Ă��邩�`�F�b�N
		bool getKeyState(int keyCode);///<������Ă邩�ǂ���

		static KeyPushed& getInstance();///<
	private:

		static bool nowKeysPushed[256];///<�L�[���͂Ɏg�p
		static bool prevKeysPushed[256];///<�L�[���͂Ɏg�p
		static char keyState[256];///<���݃t���[���Ŏ擾�����L�[�z��

		KeyPushed();
		KeyPushed(const KeyPushed& obj){};
		KeyPushed& operator=(const KeyPushed& obj){};
		
	};
	static KeyPushed& key = KeyPushed::getInstance();///<�����ŃI�u�W�F�N�g���쐬���Ă���
}