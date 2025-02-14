#pragma once
#include "../Entity/minEntity.h"
#include "minComponent.h"

namespace min
{
	struct Pos
	{
		int mX;
		int mY;
	};

	class Transform :public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetPosition(Vector2 pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
		Vector2 GetPosition() { return mPosition; }
		float GetRoation() { return mRotation; }
		Vector2 GetScale() { return mScale; }
		Vector2 GetVelocity() { return mVelocity; }
		Vector2 GetAcceleration() { return mAcceleration; }

		float GetSpeed() { return mSpeed; }

		void SetRotation(float rotate) { mRotation = rotate; }
		void SetScale(Vector2 scale) { mScale = scale; }
		void SetSpeed(float speed) { mSpeed = speed; }
		void SetAcceleration(Vector2 acc) { mAcceleration = acc; }

	private:
		Vector2 mPosition;
		Vector2 mScale;
		Vector2 mVelocity;
		Vector2 mAcceleration;
		float mRotation;
		float mSpeed;
	};
}