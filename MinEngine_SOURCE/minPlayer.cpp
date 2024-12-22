#include "minPlayer.h"
#include "minInput.h"
#include "minTime.h"
namespace min {
	Player::Player():GameObject()
	{

	}

	Player::~Player() {}

	void Player::Update()
	{
		const int speed = 100.0f;

		float delta = speed * Time::DeltaTime();

		if (Input::GetKey(eKeyCode::A))
		{
			mX -= delta;
		}
		if (Input::GetKey(eKeyCode::D))
		{
			mX += delta;
		}
		if (Input::GetKey(eKeyCode::W))
		{
			mY -= delta;
		}
		if (Input::GetKey(eKeyCode::S))
		{
			mY += delta;
		}
	}

	void Player::LateUpdate() {}
	void Player::Render(HDC hdc)
	{
		//�Ķ� �귯�� ����
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		// �Ķ� �귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ�� ��ȯ
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}