#pragma once

#include "minEntity.h"
#include "minGameObject.h"
#include "minPlayer.h"
#include "minMonster.h"

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

		void AddGameObject(GameObject* gameObject);
		void AddMonster(Monster* monster);
		void AddPlayer(Player* player);

	protected:
		std::vector<GameObject*> mGameObjects;
		std::vector<Monster*> mMonsters;
		std::vector<Player*> mPlayers;

	};
}
