#include "minTitleScene.h"
#include "../MinEngine_SOURCE/Input/minInput.h"
#include "../MinEngine_SOURCE/Scene/minSceneManager.h"
#include "../MinEngine_SOURCE/Scene/minScene.h"
#include "../MinEngine_SOURCE/Component/minTransform.h"
#include "../MinEngine_SOURCE/Component/minSpriteRenderer.h"
#include "../MinEngine_SOURCE/GameObject/minGameObject.h"
#include "../MinEngine_SOURCE/Object/minObject.h"
#include "../MinEngine_SOURCE/Resource/minResources.h"
#include "../MinEngine_SOURCE/Resource/minTexture.h"

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
		/*{
			GameObject* TitleBackground = Instantiate<GameObject>(this,eLayerType::BackGround,Vector2(0,0));

			SpriteRenderer* sr = TitleBackground->AddComponent<SpriteRenderer>();
			sr->SetName(L"SR");
			
			Texture* title = Resources::Find<Texture>(L"Title");
			sr->SetTexture(title);
			sr->SetSize(Vector2(5, 4));
		}*/

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