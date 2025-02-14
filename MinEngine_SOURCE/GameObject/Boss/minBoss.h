#pragma once

#include "..\\minGameObject.h"

namespace min
{

	class Boss : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}