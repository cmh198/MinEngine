#pragma once

#include "../Component/minComponent.h"
#include "minAnimation.h"

namespace min
{
	class Animator :public Component
	{
	public:
		Animator();
		~Animator();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void CreateAnimation(const std::wstring& name
			, Texture* spriteSheet
			, Vector2 leftTop
			, Vector2 size
			, Vector2 offset
			, UINT spriteLegth
			, float duration,bool reverse = false);
		
		Animation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop = true);
		void SetSize(Vector2 size) { mSize = size; }
		//PlayAnimation(L"move", false);
	private:
		std::map<std::wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mbLoop;
		Vector2 mSize = Vector2::One;
	};
}