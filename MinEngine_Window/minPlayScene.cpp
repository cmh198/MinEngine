#include "minPlayScene.h"
#include "minGameObject.h"
#include "minPlayer.h"
#include "Bullet.h"
#include "minInput.h"
#include "minTitleScene.h"
#include "minSceneManager.h"
#include "minTransform.h"
#include "minObject.h"
#include "minSpriteRenderer.h"

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

		AddGameObject(bg, eLayerType::BackGround);
		
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