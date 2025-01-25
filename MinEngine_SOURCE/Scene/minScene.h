#pragma once

#include "../Entity/minEntity.h"
#include "../GameObject/minGameObject.h"
#include "../GameObject/Player/minPlayer.h"
#include "../Etc/Terrain.h"
#include "minLayer.h"
#include "../Common/minEnums.h"

namespace min
{
	class Scene:public Entity
	{
	public:
		Scene();
		~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, const eLayerType type);

		Layer* GetLayer(const eLayerType type) { return mLayers[(UINT)type]; }

	protected:
		std::vector<GameObject*> mGameObjects;

	private:
		void CreateLayers();

	private:
		std::vector<Layer*> mLayers;

	};
}
