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
		virtual void SetPosition(float x, float y)=0;
		virtual float GetPositionX()=0;
		virtual float GetPositionY()=0;

	protected:
		float mX,mY;
	};
}