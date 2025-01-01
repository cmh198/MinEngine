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
		void SetPosition(float x, float y) ;
		float GetPositionX() ;
		float GetPositionY() ;
		bool GetStatus();
		void SetStatus(bool active);
		void onCollision(GameObject* other);

	private:
		bool isActive = false;
	};
}