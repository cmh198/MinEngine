#include "Bullet.h"
#include "minTime.h"
#include "minInput.h"

namespace min
{
	Bullet::Bullet(float x,float y):GameObject()
	{
		mX = x;
		mY = y;
		isActive = true;
	}
	
	Bullet::~Bullet() {}

	void Bullet::Update()
	{
		const int speed = 500;
		if (isActive)
		{
			mX += speed * Time::DeltaTime();

			//충돌 처리
			
		}
		
	}
	
	void Bullet::LateUpdate()
	{
	}
	void Bullet::Render(HDC hdc)
	{
		if (isActive)
		{
			//파랑 브러쉬 생성
			HBRUSH newBrush = CreateSolidBrush(RGB(255, 0, 0));

			// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
			HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

			HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
			HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
			SelectObject(hdc, oldPen);

			Ellipse(hdc, mX, mY, mX+10, mY+10);

			SelectObject(hdc, oldBrush);
			DeleteObject(newBrush);
			DeleteObject(redPen);
		}
		
	}
	void Bullet::SetPosition(float x, float y)
	{
		mX = x; 
		mY = y;
	}
	float Bullet::GetPositionX()
	{
		return mX;
	}
	float Bullet::GetPositionY()
	{
		return mY;
	}
	bool Bullet::GetStatus()
	{
		return isActive;
	}
	void Bullet::SetStatus(bool active)
	{
		isActive = active;
	}
	void Bullet::onCollision(GameObject* other)
	{
		if(other!=nullptr)
			bDestroyed = true;
	}
}