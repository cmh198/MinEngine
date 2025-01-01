#pragma once
#include "CommonInclude.h"

namespace min
{
	class GameObject
	{
	public:
		GameObject();
		virtual ~GameObject() {};

		virtual void Render(HDC hdc)=0;
		virtual void Update()=0;
		virtual void LateUpdate()=0;

		bool getDestroyed() { return bDestroyed; }
	protected:
		float mX,mY;
		bool bDestroyed = false;
	};
}