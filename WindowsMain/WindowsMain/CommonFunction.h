#pragma once
//============================================
//		## 자주 사용하는 함수 정의 ##
//============================================

namespace Rect
{
	//  x, y를 기준으로 widthe height를 만든다
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
	// from~to까지 랜덤 생성해주는 함수 (from은 나올수도 있다 , to는 안나온다)
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