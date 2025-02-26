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
		, curDirection(eDirection::RIGHT)
		, jumpCnt(1)
		, mTimer(0.0f)
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
			idle();
			break;
		case min::PlayerScript::eState::Run:
			run();
			break;
		case min::PlayerScript::eState::Jump:
			jump();
			break;
		case min::PlayerScript::eState::Slide:
			slide();
			break;
		default:
			break;
		}

		ApplyGravity();


	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::PlayAnimationByDirection(eDirection dir)
	{
		switch (dir)
		{
		case eDirection::LEFT:
			mAnimator->PlayAnimation(L"Player_Left_Run", true);
			break;
		case eDirection::RIGHT:
			mAnimator->PlayAnimation(L"Player_Right_Run", true);
			break;
		default:
			assert(false);
			break;
		}
	}
	void PlayerScript::ApplyGravity()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Vector2 velocity = tr->GetVelocity();

		if (!isOnGround)
		{
			velocity.y += 400.0f * Time::DeltaTime();
			pos.y += velocity.y;

			if (pos.y > 599.0f)
			{
				pos.y = 600.0f;
				velocity.y = 0.f;
				isOnGround = true;
				jumpCnt = 1;
				mTimer = 0.0f;

				//ChangeState(eState::Idle);
			}
			tr->SetPosition(pos);
		}
		else {

		}

 	}
	void PlayerScript::jump()
	{
		//mTimer += Time::DeltaTime();
		//if (isOnGround) return;
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Vector2 velocity = tr->GetVelocity();

		if (Input::GetKey(eKeyCode::A))
		{
			velocity.x -= 500.0f;
			pos.x += velocity.x * Time::DeltaTime();

			curDirection = eDirection::LEFT;
		}
		else if (Input::GetKey(eKeyCode::D))
		{
			velocity.x += 500.0f;
			pos.x += velocity.x * Time::DeltaTime();

			curDirection = eDirection::RIGHT;
		}

		if (mTimer > 0.5f)
		{

		}
		else {
			if (Input::GetKey(eKeyCode::W))
			{
				velocity.y -= 800.0f * Time::DeltaTime();
				pos.y += velocity.y;

				isOnGround = false;
			}
		}
		
		if (curDirection == eDirection::LEFT)
		{
			mAnimator->PlayAnimation(L"Player_Left_Jump", true);
		}
		else
		{
			mAnimator->PlayAnimation(L"Player_Right_Jump", true);
		}
		

		if (pos.y > 599.0f)
		{
			pos.y = 600.0f;
			velocity.y = 0.f;
			isOnGround = true;
			jumpCnt = 1;
			mTimer = 0.0f;

			ChangeState(eState::Idle);
		}

		tr->SetPosition(pos);

		
	}
	void PlayerScript::run()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float speed = tr->GetSpeed();
		Vector2 velocity = tr->GetVelocity();
		Vector2 acc = tr->GetAcceleration();

		if (!Input::GetKey(eKeyCode::D) && !Input::GetKey(eKeyCode::A))
		{
			ChangeState(eState::Idle);
			return;
		}

		if (Input::GetKey(eKeyCode::D))
		{
			velocity.x += acc.x * Time::DeltaTime();
			pos.x += velocity.x * Time::DeltaTime();

			if (curDirection == eDirection::RIGHT && mState == eState::Run)
			{

			}
			else
			{
				curDirection = eDirection::RIGHT;
				mAnimator->PlayAnimation(L"Player_Right_Run", true);
			}

		}
		else if (Input::GetKey(eKeyCode::A))
		{
			velocity.x -= acc.x * Time::DeltaTime();
			pos.x += velocity.x * Time::DeltaTime();

			if (curDirection == eDirection::LEFT && mState == eState::Run)
			{

			}
			else
			{
				curDirection = eDirection::LEFT;
				mAnimator->PlayAnimation(L"Player_Left_Run", true);
			}
		}

		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::D) || Input::GetKeyUp(eKeyCode::A)
			)
		{
			ChangeState(eState::Idle);
		}

		
		
	}
	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::D) || Input::GetKey(eKeyCode::A))
		{
			ChangeState(eState::Run);
			return;
		}
		if (Input::GetKey(eKeyCode::W) && jumpCnt > 0 && isOnGround)
		{
			isOnGround=false;
			ChangeState(eState::Jump);
			return;
		}

		if (curDirection == eDirection::LEFT)
		{
			mAnimator->PlayAnimation(L"Player_Left_Idle", true);
		}
		else if (curDirection == eDirection::RIGHT)
		{
			mAnimator->PlayAnimation(L"Player_Right_Idle", true);
		}
		else
		{

		}
	}
	void PlayerScript::slide()
	{

	}
	void PlayerScript::ChangeState(eState newState)
	{
		mState = newState;
		switch (mState) {
		case eState::Idle:
			break;
		case eState::Run:
			break;
		case eState::Jump:
			break;
		}
	}
}