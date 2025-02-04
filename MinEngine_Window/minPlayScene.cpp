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
#include "Resource/minResources.h"
#include "../MinEngine_Window/minPlayerScript.h"
#include "Camera/minCamera.h"
#include "Renderer/minRenderer.h"

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
		// main camera
		GameObject* camera = Instantiate<GameObject>(eLayerType::None, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		//camera->AddComponent<PlayerScript>();



		mPlayer = Instantiate<Player>
			(eLayerType::Player/*, Vector2(100.0f, 100.0f)*/);
		SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(3.0f, 3.0f));
		mPlayer->AddComponent<PlayerScript>();

		Texture* Player = Resources::Find<Texture>(L"Player_Right");
		sr->SetTexture(Player);

		GameObject* bg = Instantiate<GameObject>
			(eLayerType::BackGround/*, Vector2(100.0f, 100.0f)*/);
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		bgSr->SetSize(Vector2(3.0f, 3.0f));

		Texture* bgTexture = Resources::Find<Texture>(L"Map");
		bgSr->SetTexture(bgTexture);

		// 게임 오브젝트 생성후에 레이어와 게임오브젝트들의 init함수를 호출
		Scene::Initialize();
		
	}
	void PlayScene::Update()
	{
		Scene::Update();

	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::Tab))
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
		/*Transform* tr = bg->GetComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));*/
	}

}