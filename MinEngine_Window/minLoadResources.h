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
        std::wstring relativePath_MAP = L"..\\..\\minEngine_SOURCE\\MyResource\\ver1\\BackGround\\normal_map.bmp";
        std::wstring relativePath_Player = L"..\\..\\minEngine_SOURCE\\MyResource\\ver1\\Object\\x_move.bmp";
        std::wstring relativePath_Boss_Idle = L"..\\..\\minEngine_SOURCE\\MyResource\\ver2\\Enemy\\Boss\\Colonel_Idle.bmp";
        std::wstring relativePath_Boss_Slash = L"..\\..\\minEngine_SOURCE\\MyResource\\ver2\\Enemy\\Boss\\Colonel_Slash.bmp";
        std::wstring relativePath_Boss_FadeOut = L"..\\..\\minEngine_SOURCE\\MyResource\\ver2\\Enemy\\Boss\\Colonel_FadeOut.bmp";
        std::wstring relativePath_Boss_Lose = L"..\\..\\minEngine_SOURCE\\MyResource\\ver2\\Enemy\\Boss\\Colonel_Lose.bmp";
        std::wstring relativePath_AuraBlade = L"..\\..\\minEngine_SOURCE\\MyResource\\ver2\\Enemy\\Boss\\auraBlade.bmp";

        std::wstring Path_Title = exeDir + relativePath_Title;
        std::wstring Path_MAP = exeDir + relativePath_MAP;
        std::wstring Path_Player = exeDir + relativePath_Player;
        std::wstring Path_Boss_Idle = exeDir + relativePath_Boss_Idle;
        std::wstring Path_Boss_Slash = exeDir + relativePath_Boss_Slash;
        std::wstring Path_Boss_FadeOut = exeDir + relativePath_Boss_FadeOut;
        std::wstring Path_Boss_Lose = exeDir + relativePath_Boss_Lose;
        std::wstring Path_auraBlade = exeDir + relativePath_AuraBlade;

		Resources::Load<Texture>(L"Title", Path_Title);
		Resources::Load<Texture>(L"Map", Path_MAP);
		Resources::Load<Texture>(L"Player", Path_Player);
		Resources::Load<Texture>(L"Boss_Idle", Path_Boss_Idle);
		Resources::Load<Texture>(L"Boss_Slash", Path_Boss_Slash);
		Resources::Load<Texture>(L"Boss_FadeOut", Path_Boss_FadeOut);
		Resources::Load<Texture>(L"Boss_Lose", Path_Boss_Lose);
		Resources::Load<Texture>(L"AuraBlade", Path_auraBlade);
	}
}