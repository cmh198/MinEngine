#pragma once

#include "CommonInclude.h"
#include "minGameObject.h"

namespace min
{
	class Monster:public GameObject
	{
	public:
		Monster();
		~Monster();
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void SetPosition(float x, float y) override;
		float GetPositionX() override;
		float GetPositionY() override;

	private:
		
	};
}