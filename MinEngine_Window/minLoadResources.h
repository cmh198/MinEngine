#pragma once
#include "..\\minEngine_SOURCE\\Resource\minResources.h"
#include "..\\minEngine_SOURCE\\Resource/minTexture.h"

namespace min
{
	void LoadResources()
	{
        WCHAR szExePath[MAX_PATH] = { 0 };
        GetModuleFileNameW(nullptr, szExePath, MAX_PATH); // 실행 파일 경로 얻기

        std::wstring exeDir(szExePath);
        size_t pos = exeDir.find_last_of(L"\\/");
        exeDir = exeDir.substr(0, pos + 1); // 실행 파일 디렉토리

        // 상대 경로 예시: "..\\Resources\\image.bmp"
        std::wstring relativePath_Title = L"..\\..\\minEngine_SOURCE\\MyResource\\BG\\BG_TITLE_LOGO.bmp";
        std::wstring relativePath_MAP = L"..\\..\\minEngine_SOURCE\\MyResource\\BG\\BG_Stage1.png";
        std::wstring relativePath_PlayerRight = L"..\\..\\minEngine_SOURCE\\MyResource\\PLAYER\\x_right.bmp";

        std::wstring Path_Title = exeDir + relativePath_Title;
        std::wstring Path_MAP = exeDir + relativePath_MAP;
        std::wstring Path_PlayerRight = exeDir + relativePath_PlayerRight;

		Resources::Load<Texture>(L"Title", Path_Title);
		Resources::Load<Texture>(L"Map", Path_MAP);
		Resources::Load<Texture>(L"Player_Right", Path_PlayerRight);
	}
}