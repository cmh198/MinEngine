#include "minPlayer.h"
#include "minInput.h"
#include "minTime.h"
#include "minTransform.h"
#include "Bullet.h"

namespace min {

	Player::Player()
	{

	}
	Player::~Player()
	{

	}

	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();

	}

	

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
		if (Input::GetKey(eKeyCode::Right))
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
	}
	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
		////�Ķ� �귯�� ����
		//HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		//// �Ķ� �귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ�� ��ȯ
		//HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		//HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		//HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		//SelectObject(hdc, oldPen);

		//Rectangle(hdc, mX, mY, 100 + mX, 100 + mY);

		//SelectObject(hdc, oldBrush);
		//DeleteObject(blueBrush);
		//DeleteObject(redPen);

		//// �Ѿ� ������
		//for (Bullet* bullet : bullets) {
		//	if (bullet->GetStatus()) {
		//		bullet->Render(hdc);
		//	}
		//}
	}

	void Player::Shoot()
	{ 
		//�Ѿ� ����
		Bullet* newBullet = new Bullet(GetPositionX()+100, GetPositionY());
		bullets.push_back(newBullet);
	}

	void Player::onCollision(GameObject* other) 
	{

	}
}