#include "Fps.h"
#include "DxLib.h"
/**
* \namespace MKGV001
*/
namespace MKGV001{
	Fps::Fps() :checkFrameNumber(60){

		FPS = 60;
		fps = 0;
		frameInterval = 0;

		count = 0;
		startTime = 0;
		prevTime.resize(10, 0);
		
		FPSms = getFrame(FPS);
	}
	Fps::~Fps(){

	}
	/** 
	* fpsの制御
	*/
	int Fps::getFrame(int FPS){
		return  1000 / FPS;
	}
	/** 
	* fps計算
	*/
	void Fps::update(){

		if (count == 0){ //1フレーム目なら時刻を記憶
			startTime = GetNowCount();
		}
		if (count == checkFrameNumber){ //60フレーム目なら平均を計算する
			int t = GetNowCount();
			fps = 1000.f / ((t - startTime) / (float)checkFrameNumber);
			count = 0;
			startTime = t;
		}
		++count;
	}
	/**
	* 待ち時間
	*/
	void Fps::wait(){
		int tookTime = GetNowCount() - startTime;	//かかった時間
		int waitTime = count * 1000 / FPS - tookTime;	//待つべき時間
		if (waitTime > 0){
			Sleep(waitTime);	//待機
		}
	}
	/**
	* fps計算
	*/
	void Fps::updateSeGaVer(){

		int currentTime = GetNowCount();
		int frameInterval10 = currentTime - prevTime[0];
		if (count % checkFrameNumber == 0){ //60フレーム目なら平均を計算する
			frameInterval = frameInterval10 / 10;
			fps = 10 * 1000 / frameInterval10;
			count = 0;
		}
		++count;
		//履歴更新
		for (int i = 0; i < 9; ++i){
			prevTime[i] = prevTime[i + 1];
		}
		prevTime[9] = currentTime;
	}
	/**
	* 待ち時間
	*/
	void Fps::waitSeGaVer(){
		while ((GetNowCount() - prevTime[9]) < FPSms){
			Sleep(1);
		}
	}
	/**
	* 
	*/
	float Fps::getFps(){
		return fps;
	}
	/**
	* 出力
	*/
	void Fps::drawFps(){
		clsDx();
		printfDx("fps = %.2f", fps);
	}
	/**
	* fps
	*/
	void Fps::drawFpsSeGaVer(){
		clsDx();
		printfDx("frameInterval = %d", frameInterval);
		printfDx("fps = %.2f", fps);
	}
}