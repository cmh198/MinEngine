#include "minBossScript.h"
#include "../MinEngine_SOURCE/Input/minInput.h"
#include "../MinEngine_SOURCE/Component/minTransform.h"
#include "../MinEngine_SOURCE/Common/minTime.h"
#include "../MinEngine_SOURCE/GameObject/minGameObject.h"
#include "../MinEngine_SOURCE/Animation/minAnimator.h"

namespace min
{
	BossScript::BossScript()
		:mState(BossScript::eState::Idle)
		, mAnimator(nullptr)
		, mTime(0.0f)
		, mAttackTime(0.0f)
	{
	}
	BossScript::~BossScript()
	{
	}
	void BossScript::Initialize()
	{
	}
	void BossScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case BossScript::eState::Idle:
			Idle();
			break;
		case BossScript::eState::Attack:
			Attack();
			break;

		case BossScript::eState::Die:
			Die();
			break;
		default:

			break;
		}
	}
	void BossScript::LateUpdate()
	{
	}
	void BossScript::Render(HDC hdc)
	{

	}

	void BossScript::Idle()
	{
		mTime += Time::DeltaTime();

		if (mTime > 2.0f)
		{
			mState = BossScript::eState::Attack;
			mTime = 0.0f;
		}
	}
	void BossScript::Slash()
	{

		int isAngry = rand() % 2;

		if (isAngry)
		{
			//FadeOut();
			mAnimator->PlayAnimation(L"Attack_Slash_Left_Up", false);

		}
		else
		{
			mAnimator->PlayAnimation(L"Attack_Slash_Left_Down", false);
		}

	}

	void BossScript::FadeOut()
	{
		mAnimator->PlayAnimation(L"Attack_FadeOut_Left", false);
	}
	void BossScript::Attack()
	{
		if (isAttacking)
		{
			if (mAttackTime < 2.0f)
			{
				mAttackTime += Time::DeltaTime();
				return;
			}
			else
			{
				isAttacking = false;
				mAttackTime = 0;
				mTime = 0;

				mAnimator->PlayAnimation(L"Idle_Left");
				mState = eState::Idle;
				return;
			}
		}
		else
		{
			int isFadeOut = rand() % 2;

			if (isFadeOut)
			{
				FadeOut();
			}
			else {
				Slash();
			}

			isAttacking = true;
		}



	}
	void BossScript::Die()
	{

	}
}

