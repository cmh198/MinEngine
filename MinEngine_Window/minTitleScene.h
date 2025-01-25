#pragma once

#include "..\\MinEngine_SOURCE\\Scene/minScene.h"


namespace min
{
	class TitleScene :public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}