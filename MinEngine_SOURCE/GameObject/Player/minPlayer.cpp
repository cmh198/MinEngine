#include "minPlayer.h"
#include "../../Input/minInput.h"
#include "../../Component/minTransform.h"
#include "../../Etc/Bullet.h"
#include "../../Common/minTime.h"

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
		
	}
	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
		
	}

	void Player::Shoot()
	{ 
		//ÃÑ¾Ë »ý¼º
		Bullet* newBullet = new Bullet(GetPositionX()+100, GetPositionY());
		bullets.push_back(newBullet);
	}

	void Player::onCollision(GameObject* other) 
	{

	}
}