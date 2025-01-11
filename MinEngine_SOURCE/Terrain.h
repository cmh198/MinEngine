#pragma once

#include "minGameObject.h"

namespace min
{
	class Terrain:public GameObject
	{
	public:
		Terrain();
		Terrain(float x, float y, float dx, float dy) :mX(x),mY(y), dX(dx), dY(dy) {}
		~Terrain();

		void Render(HDC hdc) override;
		void Update() override;
		void LateUpdate() override;
		void SetPosition(float x, float y) override {
			mX = x;
			mY = y;
		}

	private:
		float mX, mY;
		float dX, dY;
	};
}