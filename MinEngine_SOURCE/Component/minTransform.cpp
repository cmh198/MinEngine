#include "minTransform.h"

namespace min
{
	Transform::Transform()
		:Component(eComponentType::Transform)
		, mScale(Vector2::One)
		, mRotation(0.0f)
		, mSpeed(100.0f)
		, mVelocity(Vector2::Zero)
		, mAcceleration(Vector2::One)
	{
	}
	Transform::~Transform()
	{
	}
	void Transform::Initialize()
	{
	}
	void Transform::Update()
	{
	}
	void Transform::LateUpdate()
	{
	}
	void Transform::Render(HDC hdc)
	{
	}
}