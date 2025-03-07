#include "minCamera.h"
#include "../GameObject/minGameObject.h"
#include "../Component/minTransform.h"
#include "../Apps/minApplication.h"

extern min::Application app;

namespace min
{
	Camera::Camera()
		:Component(min::eComponentType::Camera )
		,mDistance(Vector2::Zero)
		,mResolution(Vector2::Zero)
		,mLookPosition(Vector2::Zero)
		,mTarget(nullptr)
	{
	}
	Camera::~Camera()
	{
	}
	void Camera::Initialize()
	{
		mResolution.x = app.GetWidth();
		mResolution.y = app.GetHeight();
	}
	void Camera::Update()
	{
		if (mTarget)
		{
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}
		else {
			Transform* cameraTr = GetOwner()->GetComponent<Transform>();
			mLookPosition = cameraTr->GetPosition();
		}

		mDistance = mLookPosition - (mResolution / 2.0f);
	}
	void Camera::LateUpdate()
	{
	}
	void Camera::Render(HDC hdc)
	{
	}
}