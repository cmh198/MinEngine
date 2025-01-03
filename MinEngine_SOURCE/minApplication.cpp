#include "minApplication.h"
#include "minInput.h"
#include "minTime.h"
#include "minSceneManager.h"

namespace min
{
	Application::Application() :mHwnd(nullptr), mHdc(nullptr), mWidth(0), mHeight(0), mBackHdc(NULL), mBackBitmap(NULL)
	{
	}

	Application::~Application()
	{

	}

	//윈도우로부터 윈도우 핸들러 받기
	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		adjustWindowRect(hwnd, width, height);
		createBuffer(width, height);
		initializeEtc();

		SceneManager::Initialize();
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

		SceneManager::Update();


		//CheckCollision();

	}
	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		clearRenderTarget();
		Rectangle(mBackHdc, 0, 0, 1600, 900);
		Time::Render(mBackHdc);
		SceneManager::Render(mBackHdc);

		//// BackBuffer에 있는걸 원본 Buffer에 복사(그려준다)
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHdc, 0, 0, SRCCOPY);

	}

	void Application::CheckCollision()
	{
		float monsterlx = mMonster.GetPositionX();
		float monsterrx = 100 + mMonster.GetPositionX();
		float monsterty = mMonster.GetPositionY();
		float monsterby = 100 + mMonster.GetPositionY();

		for (auto bullet : mPlayer.GetBullets())
		{
			bool checkX = monsterlx <= bullet->GetPositionX() && bullet->GetPositionX() <= monsterrx;
			bool checkY = monsterty <= bullet->GetPositionY() && bullet->GetPositionY() <= monsterby;

			if (checkX && checkY)
			{
				bullet->onCollision(&mMonster);
				mMonster.onCollision(bullet);
			}
		}
	}
	void Application::clearRenderTarget()
	{
		Rectangle(mBackHdc, -1, -1, 1601, 901);
	}
	void Application::copyRenderTarget(HDC source, HDC dest)
	{
		BitBlt(dest, 0, 0, mWidth, mHeight
			, source, 0, 0, SRCCOPY);
	}
	void Application::adjustWindowRect(HWND hwnd, UINT width, UINT height)
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
	}

	void Application::createBuffer(UINT width, UINT height)
	{
		//윈도우 해상도에 맞는 백버퍼(도화지)생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		//백버퍼를 가르킬 DC생성
		mBackHdc = CreateCompatibleDC(mHdc);

		// 비트맵 선택
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);
	}

	void Application::initializeEtc()
	{
		Input::Initialize();
		Time::Initialize();
	}

}

