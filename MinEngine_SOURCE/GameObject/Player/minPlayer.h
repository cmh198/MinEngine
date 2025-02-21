#pragma once
#include "../../Common/CommonInclude.h"
#include "../minGameObject.h"
#include "../../Etc/Bullet.h"

namespace min {
	class Player :public GameObject {
	public:
		Player();
		~Player();

		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void Initialize() override;
		void SetPosition(float x, float y) 
		{
			mX = x;
			mY = y;
		}
		float GetPositionX()  { return mX; }
		float GetPositionY()  { return mY; }
		std::vector<Bullet*>& GetBullets() { return bullets; }
		void onCollision(GameObject* other) ;
		bool canShoot(float currentTime)
		{
			if (currentTime - lastusedTime >= cooldownTime)
			{
				lastusedTime = currentTime;
				return true;
			}

			return false;
		}


	private:
		std::vector<Bullet*> bullets;
		void Shoot();

		float cooldownTime = 1.0f;
		float lastusedTime = 0.0f;
	};
}