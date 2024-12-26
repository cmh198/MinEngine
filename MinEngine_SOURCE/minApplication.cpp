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

	//������κ��� ������ �ڵ鷯 �ޱ�
	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		//���� ���۸�

		//���� Client ����
		RECT rect = { 0, 0, width, height };

		//���� �������� ũ�Ⱑ Ŭ���̾�Ʈ�� ������ �ǵ��� ũ�� ����
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);


		//������ �ʺ�� ����
		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		// ���� �簢���� ������ ������ ������ ����
		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		
		//�����ֱ�
		ShowWindow(mHwnd, true);

		//������ �ػ󵵿� �´� �����(��ȭ��)����
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		//����۸� ����ų DC����
		mBackHdc = CreateCompatibleDC(mHdc);

		// ��Ʈ�� ����
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);

		mPlayer.SetPosition(0, 0);
		mMonster.SetPosition(100, 100);
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
		if (isPaused) return;
		Input::Update();
		Time::Update();

		mMonster.Update();
		mPlayer.Update();

		CheckCollision();

	}
	void Application::LateUpdate()
	{
		
	}

	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, 1600, 900);
		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);
		mMonster.Render(mBackHdc);

		// BackBuffer�� �ִ°� ���� Buffer�� ����(�׷��ش�)
		BitBlt(mHdc, 0, 0, mWidth, mHeight,mBackHdc,0,0,SRCCOPY);

	}

	void Application::CheckCollision()
	{
		float monsterlx = 400 + mMonster.GetPositionX();
		float monsterrx = 500 + mMonster.GetPositionX();
		float monsterty = 50 + mMonster.GetPositionY();
		float monsterby = 150 + mMonster.GetPositionY();

		for (auto bullet : mPlayer.GetBullets())
		{
			bool checkX = monsterlx <= bullet->GetPositionX() && bullet->GetPositionX() <= monsterrx;
			bool checkY = monsterty <= bullet->GetPositionY() && bullet->GetPositionY() <= monsterby;

			if (checkX && checkY)
			{
				bullet->onCollision(&mMonster);
				mMonster.onCollision(bullet);
				isPaused = true;
			}
		}
	}

	

}

