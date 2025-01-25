#pragma once
#include "../Entity/minEntity.h"
#include "../Common/CommonInclude.h"
#include "../GameObject/minGameObject.h"

namespace min
{
	class Layer : public Entity
	{
	public:
		Layer();
		~Layer();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObject);


	private:
		//eLayerType mType;
		std::vector<GameObject*> mGameObjects;
	};
}