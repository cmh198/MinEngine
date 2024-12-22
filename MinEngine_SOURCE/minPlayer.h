#pragma once
#include "CommonInclude.h"
#include "minGameObject.h"
#include "Bullet.h"

namespace min {
	class Player:public GameObject {
	public:
		Player();
		~Player();

		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPosition(float x, float y) override
		{
			mX = x;
			mY = y;
		}
		float GetPositionX() override { return mX+200; }
		float GetPositionY() override { return mY+150; }
		std::vector<Bullet*>& GetBullets() { return bullets; }


	private:
		std::vector<Bullet*> bullets;
		void Shoot();
	};
}