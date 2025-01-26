#include "assignmentScene.h"
#include "../MinEngine_SOURCE/Scene/minSceneManager.h"
#include "../MinEngine_SOURCE/Component/minTransform.h"
#include "../MinEngine_SOURCE/Input/minInput.h"
#include "../MinEngine_SOURCE/Object/minObject.h"
#include "../MinEngine_SOURCE/Component/minSpriteRenderer.h"
#include <cmath>

#define PI 3.141592

namespace min
{
	assignmentScene::assignmentScene()
	{
	}
	assignmentScene::~assignmentScene()
	{
	}
	void assignmentScene::Initialize()
	{
		Vector2 centerPoint = Vector2(800, 300);
		double radius = 300.0;
		for (int i = 0; i < 12; i++)
		{
			double theta = PI/6 * i;
			double x = std::cos(theta)* radius + centerPoint.x;
			double y = std::sin(theta)* radius + centerPoint.y;

			GameObject* point = Instantiate<GameObject>(eLayerType::None, Vector2(x, y));
			SpriteRenderer* sr = point->AddComponent<SpriteRenderer>();
			
			AddGameObject(point, eLayerType::None);
		}
		

		Scene::Initialize();
	}
	void assignmentScene::Update()
	{
		Scene::Update();
	}
	void assignmentScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::Tab))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}
	void assignmentScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Assignment Scene";
		TextOut(hdc, 0, 0, str, 11);
	}
	void assignmentScene::OnEnter()
	{
	}
	void assignmentScene::OnExit()
	{
	}
}