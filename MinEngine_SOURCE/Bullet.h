#pragma once
#include "minGameObject.h"

namespace min
{
	class Bullet:public GameObject
	{
	public:
		Bullet(float x,float y);
		~Bullet();

		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void SetPosition(float x, float y) override;
		float GetPositionX() override;
		float GetPositionY() override;
		bool GetStatus();
		void SetStatus(bool active);

	private:
		bool isActive = false;
	};
}