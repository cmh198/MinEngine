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
			Walk,
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
			DOWN,
			UP,
			END,
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
		void PlayAnimationByDirection();

	private:
		void jump();
		void move();

	private:
		eState mState;
		class Animator* mAnimator;

	};
}