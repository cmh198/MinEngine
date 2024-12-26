#include "minMonster.h"
#include "minInput.h"
#include "minTime.h"
#include "Bullet.h"
#include <random>

namespace min
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(-1, 1);

	Monster::Monster():GameObject()
	{ 
		mY = 0;
	}
	Monster::~Monster() {}

	void Monster::Render(HDC hdc)
	{
		//파랑 브러쉬 생성
		HBRUSH newBrush = CreateSolidBrush(RGB(255, 0, 0));

		// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Ellipse(hdc, 400 + mX, 50 + mY, 500 + mX, 150 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(newBrush);
		DeleteObject(redPen);
	}
	
	void Monster::Update()
	{
		
		const int speed = 500.0f;

		mX+= dist(gen) * speed * Time::DeltaTime();

		if (bDestroyed == true) delete this;
	}

	void Monster::LateUpdate() {}

	void Monster::SetPosition(float x, float y)
	{
		mX = x;
		mY = y;
	}

	float Monster::GetPositionX() { return mX; }
	float Monster::GetPositionY() { return mY; }

	void Monster::onCollision(GameObject* other) {
		if (dynamic_cast<Bullet*>(other) != nullptr) {
			bDestroyed = true;
		}
	}

}