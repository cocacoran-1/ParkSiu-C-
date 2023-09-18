#pragma once
//============================================
//		## ���� ����ϴ� �Լ� ���� ##
//============================================

namespace Rect
{
	//  x, y�� �������� widthe height�� �����
	inline RECT MakeRect(int x, int y, int width, int height)
	{
		RECT rc;
		rc.left = x;
		rc.top = y;
		rc.right = x + width;
		rc.bottom = y + height;

		return rc;
	}

	inline CenterRect MakeCenterRect(int x, int y, int width, int height)
	{
		CenterRect rc;
		rc.x = x;
		rc.y = y;
		rc.width = width;
		rc.height = height;

		return rc;
	}


}


namespace Draw
{
	inline void Rectangle(HDC hdc, RECT rc)
	{
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}
	inline void Rectangle(HDC hdc, CenterRect rc)
	{
		Rectangle(hdc, 
			rc.x - rc.width/2, 
			rc.y - rc.height /2, 
			rc.x + rc.width / 2, 
			rc.y + rc.height / 2);
	}
}

namespace Random
{
	// from~to���� ���� �������ִ� �Լ� (from�� ���ü��� �ִ� , to�� �ȳ��´�)
	inline int GetInt(int fromInclude, int toExclude)
	{
		return rand() % fromInclude + rand() % (toExclude - fromInclude);
	}
}

namespace Collision
{
	bool PtInRect(CenterRect rect, POINT pt);
	bool RectInRect(CenterRect rect1, CenterRect rect2);
}