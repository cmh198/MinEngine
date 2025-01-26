#pragma once
#include "..\\MinEngine_SOURCE\Scene\minScene.h"

namespace min
{
	class assignmentScene :public Scene
	{
	public:
		assignmentScene();
		~assignmentScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	};
}