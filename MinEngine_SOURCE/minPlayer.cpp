#include "minPlayer.h"
#include "minInput.h"
#include "minTime.h"
#include "Bullet.h"

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

		if (Input::GetKey(eKeyCode::Space))
		{
			if(canShoot(GetTickCount64()/1000.0f))
				Shoot();
		}

		for (size_t i = 0; i < bullets.size(); i++)
		{
			if (bullets[i]->GetStatus())
			{
				bullets[i]->Update();

				if (bullets[i]->getDestroyed() == true)
				{
					delete bullets[i];
					bullets.erase(bullets.begin() + i);
					i--;
				}
			}
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

		// �Ѿ� ������
		for (Bullet* bullet : bullets) {
			if (bullet->GetStatus()) {
				bullet->Render(hdc);
			}
		}
	}

	void Player::Shoot()
	{ 
		//�Ѿ� ����
		Bullet* newBullet = new Bullet(GetPositionX(), GetPositionY());
		bullets.push_back(newBullet);
	}

	void Player::onCollision(GameObject* other) 
	{

	}
}