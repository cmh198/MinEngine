#include "minApplication.h"
#include "minInput.h"
#include "minTime.h"
namespace min
{
	Application::Application() :mHwnd(nullptr), mHdc(nullptr),mWidth(0),mHeight(0),mBackHdc(NULL),mBackBitmap(NULL)
	{
	}

	Application::~Application()
	{

	}

	//윈도우로부터 윈도우 핸들러 받기
	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		//더블 버퍼링

		//현재 Client 영역
		RECT rect = { 0, 0, width, height };

		//현재 윈도우의 크기가 클라이언트의 영역이 되도록 크기 조정
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);


		//윈도우 너비와 높이
		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		// 얻어온 사각형의 정보로 윈도우 사이즈 세팅
		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		
		//보여주기
		ShowWindow(mHwnd, true);

		//윈도우 해상도에 맞는 백버퍼(도화지)생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		//백버퍼를 가르킬 DC생성
		mBackHdc = CreateCompatibleDC(mHdc);

		// 비트맵 선택
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);

		mPlayer.SetPosition(0, 0);
		Input::Initialize();
		Time::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();

		mPlayer.Update();
	}
	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, 1600, 900);
		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);

		// BackBuffer에 있는걸 원본 Buffer에 복사(그려준다)
		BitBlt(mHdc, 0, 0, mWidth, mHeight,mBackHdc,0,0,SRCCOPY);

	}
}

