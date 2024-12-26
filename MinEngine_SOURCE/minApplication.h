#pragma once
#include "minPlayer.h"
#include "minMonster.h"

namespace min
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd,UINT width,UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();
		void CheckCollision();

	private:
		HWND mHwnd;
		HDC mHdc;
		
		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		Player mPlayer;
		Monster mMonster;
		bool isPaused = false;
	};
}