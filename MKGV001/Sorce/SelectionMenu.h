/** \file
 * ���j���[���ڂ𑀍�
 */
#include <vector>
#include <string>
/**
* \namespace MKGV001
*/
namespace MKGV001{
	/**
	 * ���j���[���ڂ𑀍�
	 */
	class SelectionMenu{
	public:
		SelectionMenu();
		~SelectionMenu();
		void add(int x, int y, std::string str, int color);///<�V�������ڂ̒ǉ�
		void draw();///<menuList�S�f�[�^��`��
		void numCursor(int num);///<�L�[�������ꂽ�画�f
		void drawCursor();//���ݎw���Ă���J�[�\���̕`��
		int getCursor();
	private:

		struct Data{//�`�掞�ɕK�v�ȃf�[�^�Q
			std::string str;
			int x;
			int y;
			int color;
		};
		std::vector<Data> menuList;//�ǉ����ꂽ���j���[�p�`��f�[�^
		int cursor;//���ݎw���Ă�f�[�^
		
	};
}