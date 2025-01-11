#pragma once
#include "CommonInclude.h"

namespace min
{
	class GameObject
	{
	public:
		GameObject();
		GameObject(float x, float y) :mX(x), mY(y) {}
		virtual ~GameObject() {};

		virtual void Render(HDC hdc)=0;
		virtual void Update()=0;
		virtual void LateUpdate()=0;
		virtual void SetPosition(float x,float y)=0;

		bool getDestroyed() { return bDestroyed; }
	protected:
		float mX,mY;
		bool bDestroyed = false;
	};
}