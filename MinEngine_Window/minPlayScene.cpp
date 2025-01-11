#include "minPlayScene.h"
#include "minGameObject.h"
#include "minPlayer.h"
#include "minMonster.h"
#include "Bullet.h"
#include "Terrain.h"

#include <vector>

namespace min
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
		for (auto monster : mMonsters)
		{
			delete monster;
		}

		for (auto gameObject : mGameObjects)
		{
			delete gameObject;
		}

		for (auto player : mPlayers)
		{
			delete player;
		}

		mMonsters.clear();
		mGameObjects.clear();
		mPlayers.clear();
	}
	void PlayScene::Initialize()
	{
		Player* player = new Player(100, 100);

		Monster* monster= new Monster(400,100);

		Monster* monster2= new Monster(400,400);
		
		Terrain* ground = new Terrain(0, 800, 1600, 100);

		
		AddTerrain(ground);
		AddPlayer(player);
		AddMonster(monster);
		AddMonster(monster2);
	}
	void PlayScene::Update()
	{
		Scene::Update();

		HandleCollision();
		ClearDeadObject();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void PlayScene::HandleCollision()
	{
		for (Player* player : mPlayers)
		{
			std::vector<Bullet*> bullets = player->GetBullets();

			//monster 순회해서 bullet과 충돌처리

			for (Monster* monster : mMonsters)
			{
				float monsterlx = monster->GetPositionX();
				float monsterrx = 100 + monster->GetPositionX();
				float monsterty = monster->GetPositionY();
				float monsterby = 100 + monster->GetPositionY();

				for (Bullet* bullet : bullets)
				{
					bool checkX = monsterlx <= bullet->GetPositionX() && bullet->GetPositionX() <= monsterrx;
					bool checkY = monsterty <= bullet->GetPositionY() && bullet->GetPositionY() <= monsterby;

					if (checkX && checkY)
					{
						bullet->onCollision(monster);
						monster->onCollision(bullet);
					}
				}
			}
		}
	}

	void PlayScene::ClearDeadObject()
	{
		for (auto it = mMonsters.begin(); it != mMonsters.end();)
		{
			if ((*it)->GetDestroyed()) {
				delete* it;
				it = mMonsters.erase(it);
			}
			else {
				++it;
			}
		}
	}

}