#include "Terrain.h"

namespace min
{
	Terrain::Terrain()
	{
	}
	Terrain::~Terrain()
	{
	}
	void Terrain::Render(HDC hdc)
	{
		//파랑 브러쉬 생성
		HBRUSH newBrush = CreateSolidBrush(RGB(0, 0, 0));

		// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Rectangle(hdc, mX, mY, dX + mX, dY + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(newBrush);
		DeleteObject(redPen);
	}
	void Terrain::Update()
	{
	}
	void Terrain::LateUpdate()
	{

	}
}

