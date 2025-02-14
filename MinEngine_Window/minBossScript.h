#pragma once
#include "../MinEngine_SOURCE/Script/minScript.h"
#include "../MinEngine_SOURCE/Component/minTransform.h"


namespace min
{
	class BossScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Attack,
			Die,
		};

		enum class eDirection
		{
			LEFT,
			RIGHT,
		};

		BossScript();
		~BossScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void Idle();
		void Slash();
		void Attack();
		void Die();
		void FadeOut();

	private:
		eState mState;
		class Animator* mAnimator;
		eDirection mDirection;
		float mTime;
		float mAttackTime;

		bool isAttacking = false;

	};
}