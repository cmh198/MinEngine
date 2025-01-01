#pragma once
#include "..\\MinEngine_SOURCE\minScene.h"

namespace min
{
	class PlayScene :public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void HandleCollision();

		void ClearDeadObject();

	private:
	};
}