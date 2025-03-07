#pragma once
#include "../Common/CommonInclude.h"
#include "../Component/minComponent.h"

namespace min::object
{
	void Destroy(GameObject* gameObject);
}

namespace min
{
	class GameObject
	{
	public:
		friend void object::Destroy(GameObject* obj);
		enum class eState
		{
			Active,
			Paused,
			Dead,
			End
		};

		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Render(HDC hdc);
		virtual void Update();
		virtual void LateUpdate();

		template<typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);
			mComponents[(UINT)comp->GetType()] = comp;

			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}

			return component;
		}

		eState GetState() { return mState; }
		void SetActive(bool power)
		{
			if (power == true) mState = eState::Active;
			if (power == false) mState = eState::Paused;
		}
		bool IsActive() { return mState == eState::Active; }
		void Death() { mState = eState::Dead; }
		bool IsDead() { return mState == eState::Dead; }
		bool getDestroyed() { return bDestroyed; }
	protected:
		float mX=0,mY=0;
		bool bDestroyed = false;

	private:
		void InitializeTransform();
	private:
		eState mState;
		std::vector<Component*> mComponents;
	};
}