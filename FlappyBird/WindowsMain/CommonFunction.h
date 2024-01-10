#pragma once
//===========================================
//    ## ���� ����ϴ� �Լ� ���� ##
//		(���� �߰��ؼ� �����)
//===========================================

struct Vector2Int;
// �簢�� ���õ� �Լ�
namespace Shape
{
	//x, y�� ��������  width height�� �����.
	inline RECT MakeRect(int x, int y, int width, int height)
	{
		RECT rc;
		rc.left = x;
		rc.top = y;
		rc.right = x + width;
		rc.bottom = y + height;

		return rc;
	}

	//x, y�� ���Ͷ�� ����������  width height�� �簢���� �����.
	inline CenterRect MakeCenterRect(float x, float y, float width, float height)
	{
		CenterRect rc;
		rc.x = x;
		rc.y = y;
		rc.width = width;
		rc.height = height;

		return rc;
	}

	inline CenterCircle MakeCenterCircle(float x, float y, float radius)
	{
		CenterCircle c;
		c.center.x = x;
		c.center.y = y;
		c.radius = radius;

		return c;
	}

	inline void ChangeToNormalValue(RECT& rc)
	{
		if (rc.left > rc.right)
		{
			LONG tmp = rc.left;
			rc.left = rc.right;
			rc.right = tmp;
		}
		if (rc.top > rc.bottom)
		{
			LONG tmp = rc.top;
			rc.top = rc.bottom;
			rc.bottom = tmp;
		}
	}
}


namespace Draw
{
	inline void Rect(HDC hdc, RECT rc)
	{
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}

	void Rect(HDC hdc, RECT rc, Vector2Int cameraPos);

	inline void Rect(HDC hdc, CenterRect rc)
	{
		Rectangle(hdc, 
			static_cast<int>(rc.x - rc.width / 2),	//left
			static_cast<int>(rc.y - rc.height / 2),	//top
			static_cast<int>(rc.x + rc.width / 2),	//right
			static_cast<int>(rc.y + rc.height / 2)	//bottom
		);
	}

	inline void Circle(HDC hdc, RECT rc)
	{
		Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}

	inline void Circle(HDC hdc, CenterRect rc)
	{
		Ellipse(hdc,
			static_cast<int>(rc.x - rc.width / 2),	//left
			static_cast<int>(rc.y - rc.height / 2),	//top
			static_cast<int>(rc.x + rc.width / 2),	//right
			static_cast<int>(rc.y + rc.height / 2)	//bottom
		);
	}

	inline void Line(HDC hdc, Vector2 startPos, Vector2 endPos)
	{
		MoveToEx(hdc, static_cast<int>(startPos.x), static_cast<int>(startPos.y), (LPPOINT)NULL);
		LineTo(hdc, static_cast<int>(endPos.x), static_cast<int>(endPos.y));
	}

}

namespace Random
{
	//from ~ to���� �����������ִ� �Լ� (from �� ���ü�������, to�� �ȳ���)
	inline int GetInt(int fromInclude, int toExclude)
	{
		return fromInclude + rand() % (toExclude - fromInclude);
	}

	//from ~ to���� �����������ִ� �Լ� (from �� ���ü�������, to�� �ȳ���)
	inline float GetFloat(float fromInclude, float toExclude)
	{
		//0 ~ 1������ ����
		float random = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		//0 ~ 500 ������ ������ �Ǽ� ����
		//random * 500
		return fromInclude + (random * (toExclude - fromInclude));
	}
}

namespace Collision
{
	bool PtInRect(CenterRect rect, POINT pt);
	bool RectInRect(CenterRect rect1, CenterRect rect2);
	bool CircleInCircle(CenterCircle c1, CenterCircle c2);
	bool RectInCircle(CenterRect rect, CenterCircle circle);
}