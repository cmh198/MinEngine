#include "minTitleScene.h"
#include "../MinEngine_SOURCE/Input/minInput.h"
#include "../MinEngine_SOURCE/Scene/minSceneManager.h"
#include "../MinEngine_SOURCE/Scene/minScene.h"
#include "../MinEngine_SOURCE/Component/minTransform.h"
#include "../MinEngine_SOURCE/Component/minSpriteRenderer.h"
#include "../MinEngine_SOURCE/GameObject/minGameObject.h"
#include "../MinEngine_SOURCE/Object/minObject.h"

namespace min
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		//Title Scene
		{
			GameObject* TitleBackground = Instantiate<GameObject>(this,eLayerType::BackGround,Vector2(800,450));

			SpriteRenderer* sr = TitleBackground->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			AddGameObject(TitleBackground,eLayerType::BackGround);
		}
	}
	void TitleScene::Update()
	{
		Scene::Update();
	}
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::Tab))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);
	}
}