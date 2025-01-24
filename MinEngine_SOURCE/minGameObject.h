#pragma once
#include "CommonInclude.h"
#include "minComponent.h"


namespace min
{
	class GameObject
	{
	public:
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
			mComponents.push_back(comp);

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

		bool getDestroyed() { return bDestroyed; }
	protected:
		float mX=0,mY=0;
		bool bDestroyed = false;

	private:
		void InitializeTransform();
	private:
		std::vector<Component*> mComponents;
	};
}