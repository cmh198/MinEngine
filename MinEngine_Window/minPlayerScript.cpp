#include "minPlayerScript.h"
#include "../MinEngine_SOURCE/Input/minInput.h"
#include "../MinEngine_SOURCE/Component/minTransform.h"
#include "../MinEngine_SOURCE/GameObject/minGameObject.h"
#include "../MinEngine_SOURCE/Common/minTime.h"
#include "../MinEngine_SOURCE/Animation/minAnimator.h"

namespace min
{
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Idle)
		, mAnimator(nullptr)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case min::PlayerScript::eState::Idle:
			move();
			break;
		case min::PlayerScript::eState::Jump:
			jump();
			break;
		case min::PlayerScript::eState::Walk:
			move();
			break;

		case min::PlayerScript::eState::Run:
			break;
		case min::PlayerScript::eState::Shoot:
			break;
		default:
			
			break;
		}
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::jump()
	{

	}
	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float speed = tr->GetSpeed();
		Vector2 velocity = tr->GetVelocity();
		Vector2 acc = tr->GetAcceleration();
		if (Input::GetKey(eKeyCode::D))
		{
			velocity.x += acc.x * Time::DeltaTime();
			pos.x += velocity.x * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::A))
		{
			velocity.x -= acc.x * Time::DeltaTime();
			pos.x += velocity.x * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::W))
		{
			if (velocity.y == 0.f)
			{
				velocity.y -= 800.0f;
				pos.y += velocity.y * Time::DeltaTime();
			}
		}
		
		if (pos.y > 499.0f)
		{
			pos.y = 500.0f;
			velocity.y = 0.f;
		}
		else {
			velocity.y += 30000.0f * Time::DeltaTime();
			pos.y += velocity.y * Time::DeltaTime();
		}
		
		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::D) || Input::GetKeyUp(eKeyCode::A)
			|| Input::GetKeyUp(eKeyCode::W) || Input::GetKeyUp(eKeyCode::S))
		{
			/*mState = PlayerScript::eState::SitDown;
			mAnimator->PlayAnimation(L"SitDown", false);*/
		}
	}
}