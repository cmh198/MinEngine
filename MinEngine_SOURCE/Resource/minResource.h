#pragma once

#include "../Entity/minEntity.h"

namespace min
{
	class Resource abstract :public Entity
	{
	public:
		Resource(eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;

		const std::wstring& GetPath() { return  mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const eResourceType mType;
		std::wstring mPath;

	};
}
