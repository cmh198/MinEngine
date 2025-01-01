#include "minScene.h"

namespace min
{
	Scene::Scene() :mGameObjects{}
	{

	}
	Scene::~Scene()
	{

	}

	void Scene::Initialize()
	{

	}

	void Scene::Update()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Update();
		}
		for (GameObject* gameObj : mMonsters)
		{
			gameObj->Update();
		}
		for (GameObject* gameObj : mPlayers)
		{
			gameObj->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->LateUpdate();
		}
		for (GameObject* gameObj : mMonsters)
		{
			gameObj->LateUpdate();
		}
		for (GameObject* gameObj : mPlayers)
		{
			gameObj->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (GameObject* gameObj : mGameObjects)
		{
			gameObj->Render(hdc);
		}
		for (GameObject* gameObj : mMonsters)
		{
			if(gameObj->getDestroyed()==false)
				gameObj->Render(hdc);
		}
		for (GameObject* gameObj : mPlayers)
		{
			gameObj->Render(hdc);
		}
	}

	void Scene::AddGameObject(GameObject* gameObject)
	{
		mGameObjects.push_back(gameObject);
	}

	void Scene::AddMonster(Monster* monster)
	{
		mMonsters.push_back(monster);
	}

	void Scene::AddPlayer(Player* player)
	{
		mPlayers.push_back(player);
	}

}