#include "minSpriteRenderer.h"
#include "minGameObject.h"
#include "minTransform.h"


namespace min
{
	SpriteRenderer::SpriteRenderer() 
		: mImgae(nullptr)
		, mWidth(0)
		, mHeight(0)
	{
	}
	SpriteRenderer::~SpriteRenderer()
	{
	}
	void SpriteRenderer::Initialize()
	{
	}
	void SpriteRenderer::Update()
	{
	}
	void SpriteRenderer::LateUpdate()
	{
	}
	void SpriteRenderer::Render(HDC hdc)
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		//파랑 브러쉬 생성
		HBRUSH newBrush = CreateSolidBrush(RGB(255, 0, 0));

		// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Rectangle(hdc, pos.x, pos.y, 100 + pos.x, 100 + pos.y);

		SelectObject(hdc, oldBrush);
		DeleteObject(newBrush);
		DeleteObject(redPen);

		/*Gdiplus::Graphics graphcis(hdc);
		graphcis.DrawImage(mImgae, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));*/
	}
	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		mImgae = Gdiplus::Image::FromFile(path.c_str());
		mWidth = mImgae->GetWidth();
		mHeight = mImgae->GetHeight();
	}

}