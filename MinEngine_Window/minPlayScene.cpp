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
		//PlayScene
		{
			bg = Instantiate<Player>(this,eLayerType::Player, Vector2(500, 500));

			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();

			AddGameObject(bg, eLayerType::Player);
		}
		
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