#pragma once

#include "minEntity.h"
#include "minGameObject.h"
#include "minPlayer.h"
#include "Terrain.h"
#include "minLayer.h"
#include "minEnums.h"

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
