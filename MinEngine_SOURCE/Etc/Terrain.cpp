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
		//�Ķ� �귯�� ����
		HBRUSH newBrush = CreateSolidBrush(RGB(0, 0, 0));

		// �Ķ� �귯�� DC�� ���� �׸��� ��� �귯�� ��ȯ�� ��ȯ
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

