#pragma once
#include "../Common/CommonInclude.h"

namespace min
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& GetName() { return mName; } 
	private:
		std::wstring mName;
	};
}