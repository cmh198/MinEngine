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
#include "../MinEngine_SOURCE/Animation/minAnimator.h"
#include <vector>

#include "GameObject/Boss/minBoss.h"
#include "../MinEngine_Window/minBossScript.h"
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
		{
			GameObject* camera = Instantiate<GameObject>(eLayerType::None, Vector2(1000.0f, 450.0f));
			Camera* cameraComp = camera->AddComponent<Camera>();
			renderer::mainCamera = cameraComp;
			//camera->AddComponent<PlayerScript>();
		}
		
		// Player
		{
			mPlayer = Instantiate<Player>
				(eLayerType::Player, Vector2(500.0f, 400.0f));
			mPlayer->AddComponent<PlayerScript>();
			mPlayer->GetComponent<Transform>()->SetSpeed(200.0f);
			mPlayer->GetComponent<Transform>()->SetAcceleration(Vector2(50000.0f, 5000.0f));

			Texture* playerTexture = Resources::Find<Texture>(L"Player");

			Animator* playerAnim = mPlayer->AddComponent<Animator>();
			playerAnim->SetSize(Vector2(3.0f, 3.0f));

			playerAnim->CreateAnimation(L"Player_Right_Idle", playerTexture, Vector2(0.0f, 0.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 4, 0.1f);
			playerAnim->CreateAnimation(L"Player_Left_Idle", playerTexture, Vector2(0.0f, 128.0f), Vector2(128.0f, 128.0f), Vector2::Zero, 4, 0.1f);
			playerAnim->CreateAnimation(L"Player_Right_Run", playerTexture, Vector2(0.0f, 128.0f * 2), Vector2(128.0f, 128.0f), Vector2::Zero, 14, 0.05f);
			playerAnim->CreateAnimation(L"Player_Left_Run", playerTexture, Vector2(0.0f, 128.0f * 3), Vector2(128.0f, 128.0f), Vector2::Zero, 14, 0.05f);
			playerAnim->CreateAnimation(L"Player_Right_Slide", playerTexture, Vector2(0.0f, 128.0f * 4), Vector2(128.0f, 128.0f), Vector2::Zero, 10, 0.03f);
			playerAnim->CreateAnimation(L"Player_Left_Slide", playerTexture, Vector2(0.0f, 128.0f * 5), Vector2(128.0f, 128.0f), Vector2::Zero, 10, 0.03f);
			playerAnim->CreateAnimation(L"Player_Right_Jump", playerTexture, Vector2(0.0f, 128.0f * 6), Vector2(128.0f, 128.0f), Vector2::Zero, 11, 0.05f);
			playerAnim->CreateAnimation(L"Player_Left_Jump", playerTexture, Vector2(0.0f, 128.0f * 7), Vector2(128.0f, 128.0f), Vector2::Zero, 11, 0.05f,true);
			playerAnim->CreateAnimation(L"Player_Right_Hang", playerTexture, Vector2(0.0f, 128.0f * 8), Vector2(128.0f, 128.0f), Vector2::Zero, 6, 0.1f);
			playerAnim->CreateAnimation(L"Player_Left_Hang", playerTexture, Vector2(0.0f, 128.0f * 9), Vector2(128.0f, 128.0f), Vector2::Zero, 6, 0.1f);
			playerAnim->CreateAnimation(L"Player_Right_Die", playerTexture, Vector2(0.0f, 128.0f * 10), Vector2(128.0f, 128.0f), Vector2::Zero, 5, 0.1f);
			playerAnim->CreateAnimation(L"Player_Left_Die", playerTexture, Vector2(0.0f, 128.0f * 11), Vector2(128.0f, 128.0f), Vector2::Zero, 5, 0.1f);

			playerAnim->PlayAnimation(L"Player_Right_Idle", true);
		}

		Boss* boss = Instantiate<Boss>(eLayerType::Enemy, Vector2(1000, 500));
		boss->AddComponent<BossScript>();

		Texture* boss_Idle = Resources::Find<Texture>(L"Boss_Idle");
		Texture* boss_Slash = Resources::Find<Texture>(L"Boss_Slash");
		Texture* boss_FadeOut = Resources::Find<Texture>(L"Boss_FadeOut");
		Texture* boss_Lose = Resources::Find<Texture>(L"Boss_Lose");
		Texture* auraBlade = Resources::Find<Texture>(L"AuraBlade");

		Animator* bossAnim = boss->AddComponent<Animator>();
		bossAnim->CreateAnimation(L"Idle_Right", boss_Idle, Vector2(0, 146), Vector2(186, 146), Vector2::Zero, 3, 0.1f);
		bossAnim->CreateAnimation(L"Idle_Left", boss_Idle, Vector2(0, 0), Vector2(186, 146), Vector2::Zero, 3, 0.5f);
		bossAnim->CreateAnimation(L"Attack_FadeOut_Left", boss_FadeOut, Vector2(0, 0), Vector2(174, 132), Vector2::Zero, 4, 0.1f);
		bossAnim->CreateAnimation(L"Attack_FadeOut_Right", boss_FadeOut, Vector2(0, 132), Vector2(174, 132), Vector2::Zero, 4, 0.5f);
		bossAnim->CreateAnimation(L"Attack_Slash_Left_Down", boss_Slash, Vector2(0, 0), Vector2(278, 208), Vector2::Zero, 5, 0.1f);
		bossAnim->CreateAnimation(L"Attack_Slash_Left_Up", boss_Slash, Vector2(278*5, 0), Vector2(278, 208), Vector2::Zero, 6, 0.1f);
		bossAnim->CreateAnimation(L"Attack_Slash_Right_Down", boss_Slash, Vector2(0, 208), Vector2(278, 208), Vector2::Zero, 6, 0.1f, true);
		bossAnim->CreateAnimation(L"Attack_Slash_Right_Up", boss_Slash, Vector2(278*6, 208), Vector2(278, 208), Vector2::Zero, 5, 0.1f, true);

		bossAnim->PlayAnimation(L"Idle_Left");

		{
			GameObject* bg = Instantiate<GameObject>
				(eLayerType::BackGround, Vector2(0.0f, 75.0f));
			SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
			bgSr->SetSize(Vector2(3.f, 3.f));

			Texture* bgTexture = Resources::Find<Texture>(L"Map");
			bgSr->SetTexture(bgTexture);
		}

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