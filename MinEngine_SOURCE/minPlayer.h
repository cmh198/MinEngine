#pragma once
#include "CommonInclude.h"
#include "minGameObject.h"

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
		float GetPositionX() override { return mX; }
		float GetPositionY() override { return mY; }
	private:
		
	};
}