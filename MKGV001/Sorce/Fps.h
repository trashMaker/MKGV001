/** \file
 * fpsの制御
 */
#include <vector>
/**
 * \namespace MKGV001
 */
namespace MKGV001{
	/** \file
	* fpsの制御
	*/
	class Fps{
	public:
		Fps();
		~Fps();
		void update();///<fps計算
		void updateSeGaVer();///<fps計算
		void wait();
		void waitSeGaVer();
		void drawFps();
		void drawFpsSeGaVer();
		float getFps();
		int getFrame(int FPS);

	private:
		int count;///<
		int startTime;///<
		int frameInterval;///<
		float fps;///<
		const int checkFrameNumber;///<

		int FPS;///<
		float FPSms;///<

		std::vector<int> prevTime;///< 平均フレームを出す用
	};
}