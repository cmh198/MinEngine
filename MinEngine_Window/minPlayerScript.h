#pragma once
#include "../MinEngine_SOURCE/Script/minScript.h"


namespace min
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Run,
			Jump,
			Slide,
			Shoot,
			Charge,
			Hang,
			Die,
		};

		enum class eDirection
		{
			LEFT,
			RIGHT,
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void PlayAnimationByDirection(eDirection dir);
		void ApplyGravity();

	private:
		void jump();
		void run();
		void idle();
		void slide();
		void ChangeState(eState newState);

	private:
		eState mState;
		class Animator* mAnimator;
		eDirection curDirection;

		bool isJump = false;
		bool isOnGround = false;

		int jumpCnt;
		float mTimer;

	};
}