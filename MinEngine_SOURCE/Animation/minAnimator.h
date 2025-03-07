#pragma once

#include "../Component/minComponent.h"
#include "minAnimation.h"

namespace min
{
	class Animator :public Component
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}

			void operator()()
			{
				if (mEvent)
					mEvent();
			}

			std::function<void()> mEvent;
		};

		struct Events
		{
			Event startEvent;
			Event completeEvent;
			Event endEvent;
		};
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

		void CreateAnimationByFolder(const std::wstring& name
			, const std::wstring& path
			, Vector2 offset, float duration);

		Animation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop = true);
		Events* FindEvents(const std::wstring& name);
		std::function<void()>& GetStartEvent(const std::wstring& name);
		std::function<void()>& GetCompleteEvent(const std::wstring& name);
		std::function<void()>& GetEndEvent(const std::wstring& name);

		bool IsComplete() { return mActiveAnimation->IsComplete(); }

		void SetSize(Vector2 size) { mSize = size; }
		//PlayAnimation(L"move", false);
	private:
		std::map<std::wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mbLoop;
		Vector2 mSize = Vector2::One;

		//Event
		std::map<std::wstring, Events*> mEvents;
	};
}