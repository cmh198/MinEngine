#include "minPlayScene.h"
#include "../MinEngine_SOURCE/GameObject/minGameObject.h"
#include "../MinEngine_SOURCE/GameObject/Player/minPlayer.h"
#include "../MinEngine_SOURCE/Etc/Bullet.h"
#include "../MinEngine_SOURCE/Input/minInput.h"
#include "minTitleScene.h"
#include "../MinEngine_SOURCE/Scene/minSceneManager.h"
#include "../MinEngine_SOURCE/Component/minTransform.h"
#include "../MinEngine_SOURCE/Object/minObject.h"
#include "../MinEngine_SOURCE/Component/minSpriteRenderer.h"

#include <vector>

namespace min
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
		
	}

	void PlayScene::Initialize()
	{
		bg = new Player();
		Transform* tr
			= bg->GetComponent<Transform>();
		tr->SetPosition(Vector2(500, 500));

		tr->SetName(L"TR");

		SpriteRenderer* sr
			= bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		

		AddGameObject(bg, eLayerType::Player);
		
	}
	void PlayScene::Update()
	{
		Scene::Update();

	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
		
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);

	}

	
	

	void PlayScene::OnEnter()
	{

	}
	void PlayScene::OnExit()
	{
		Transform* tr = bg->GetComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));
	}

}