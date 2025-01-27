#pragma once
#include "..\\minEngine_SOURCE\\Resource\minResources.h"
#include "..\\minEngine_SOURCE\\Resource/minTexture.h"

namespace min
{
	void LoadResources()
	{
        WCHAR szExePath[MAX_PATH] = { 0 };
        GetModuleFileNameW(nullptr, szExePath, MAX_PATH); // ���� ���� ��� ���

        std::wstring exeDir(szExePath);
        size_t pos = exeDir.find_last_of(L"\\/");
        exeDir = exeDir.substr(0, pos + 1); // ���� ���� ���丮

        // ��� ��� ����: "..\\Resources\\image.bmp"
        std::wstring relativePath = L"..\\..\\minEngine_SOURCE\\MyResource\\BG\\BG_TITLE_LOGO.bmp";
        std::wstring absolutePath = exeDir + relativePath;

		Resources::Load<Texture>(L"Title", absolutePath);
	}
}