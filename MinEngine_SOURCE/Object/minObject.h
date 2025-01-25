#pragma once
#include "../Component/minComponent.h"
#include "../GameObject/minGameObject.h"
#include "../Scene/minLayer.h"
#include "../Scene/minScene.h"
#include "../Scene/minSceneManager.h"
#include "../Component/minTransform.h"


namespace min
{
	template <typename T>
	static T* Instantiate(min::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(min::eLayerType type, Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}
}