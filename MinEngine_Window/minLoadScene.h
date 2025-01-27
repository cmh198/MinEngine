#pragma once
#include "..\\MinEngine_SOURCE\\Scene\\minSceneManager.h"

#include "minPlayScene.h"
#include "minTitleScene.h"
#include "assignmentScene.h"

namespace min
{
	void LoadScenes()
	{
		//SceneManager::CreateScene<assignmentScene>(L"assignmentScene");
		SceneManager::CreateScene<TitleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		//SceneManager::LoadScene(L"assignmentScene");
		SceneManager::LoadScene(L"TitleScene");
		//SceneManager::LoadScene(L"PlayScene");
	}
}