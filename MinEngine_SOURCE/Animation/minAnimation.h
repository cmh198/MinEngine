#pragma once

#include "../Resource/minResource.h"
#include "../Resource/minTexture.h"

namespace min
{
	class Animation :public Resource
	{
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite()
				: leftTop(Vector2::Zero)
				, size(Vector2::Zero)
				, offset(Vector2::Zero)
				, duration(0.0f)
			{

			}
		};

		Animation();
		~Animation();

		HRESULT Load(const std::wstring& path) override;

		void Update();
		void Render(HDC hdc);

		void CreateAnimation(const std::wstring& name
			, Texture* spriteSheet
			, Vector2 leftTop
			, Vector2 sizei
			, Vector2 offset
			, UINT spriteLegth
			, float duration,bool reverse = false);

		void Reset();

		bool IsComplete() { return mbComplete; }
		void SetAnimator(class Animator* animator) { mAnimator = animator; }
		void SetSize(Vector2 size) { mSize = size; }
	private:
		class Animator* mAnimator;
		Texture* mTexture;

		std::vector<Sprite> mAnimationSheet;
		int mIndex;
		float mTime;
		bool mbComplete;

		Vector2 mSize = Vector2::One;
	};
}