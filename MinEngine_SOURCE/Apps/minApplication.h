#pragma once
#include "../GameObject/Player/minPlayer.h"

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

	private:

		void clearRenderTarget();
		void copyRenderTarget(HDC sourc,HDC dest);
		void adjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();


		HWND mHwnd;
		HDC mHdc;
		
		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;

		Player mPlayer;
		bool isPaused = false;
	};
}