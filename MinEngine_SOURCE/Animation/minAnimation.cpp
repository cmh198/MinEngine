#include "minAnimation.h"
#include "../Common/minTime.h"
#include "../Component/minTransform.h"
#include "../GameObject/minGameObject.h"
#include "minAnimator.h"
#include "../Renderer/minRenderer.h"
#include "../Camera/minCamera.h"

namespace min
{
	Animation::Animation()
		: Resource(eResourceType::Animation)
		, mAnimator(nullptr)
		, mTexture(nullptr)
		, mAnimationSheet{}
		, mIndex(-1)
		, mTime(0.0f)
		, mbComplete(false)
	{
	}

	Animation::~Animation()
	{
	}

	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	void Animation::Update()
	{
		if (mbComplete)
			return;

		mTime += Time::DeltaTime();

		if (mAnimationSheet[mIndex].duration < mTime)
		{
			mTime = 0.0f;
			if (mIndex < mAnimationSheet.size() - 1)
				mIndex++;
			else
				mbComplete = true;
		}
	}

	void Animation::Render(HDC hdc)
	{
		// ���ĺ��带 ���� �ִ� ���� : �ش��̹��� ����ä���� �־���Ѵ�.
		//AlphaBlend(125, );


		if (mTexture == nullptr)
			return;

		GameObject* gameObj = mAnimator->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rot = tr->GetRoation();
		Vector2 scale = tr->GetScale();

		if (renderer::mainCamera)
			pos = renderer::mainCamera->CalculatePosition(pos);


		Sprite sprite = mAnimationSheet[mIndex];
		HDC imgHdc = mTexture->GetHdc();



		if (mTexture->GetTextureType()
			== Texture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x - (sprite.size.x / 2.0f), pos.y - (sprite.size.y / 2.0f)
				, sprite.size.x * mSize.x, sprite.size.y * mSize.y
				, imgHdc, sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y
				, RGB(255, 0, 255));
		}
		else if (mTexture->GetTextureType()
			== Texture::eTextureType::Png)
		{
			// ���� ���ϴ� �ȼ��� ����ȭ ��ų��
			Gdiplus::ImageAttributes imgAtt = {};

			// ����ȭ ��ų �ȼ��� �� ����
			imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rot);
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(mTexture->GetImage()
				, Gdiplus::Rect
				(
					pos.x - (sprite.size.x / 2.0f)
					, pos.y - (sprite.size.y / 2.0f)
					, sprite.size.x * scale.x
					, sprite.size.y * scale.y
				)
				, sprite.leftTop.x
				, sprite.leftTop.y
				, sprite.size.x
				, sprite.size.y
				, Gdiplus::UnitPixel
				, /*&imgAtt*/nullptr
			);
		}


	}

	void Animation::CreateAnimation(const std::wstring& name, Texture* spriteSheet
		, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLegth, float duration, bool reverse )
	{
		mTexture = spriteSheet;
		for (size_t i = 0; i < spriteLegth; i++)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (size.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			mAnimationSheet.push_back(sprite);
			if (reverse == true)
			{
				std::reverse(mAnimationSheet.begin(), mAnimationSheet.end());
			}
		}
	}

	void Animation::Reset()
	{
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}
}