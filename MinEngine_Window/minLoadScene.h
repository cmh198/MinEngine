#pragma once
#include "..\\MinEngine_SOURCE\\minSceneManager.h"

#include "minPlayScene.h"

namespace min
{
	void LoadScenes()
	{
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}