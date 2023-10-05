#pragma once
//===========================================
//    ## ���� ����ϴ� �Լ� ���� ##
//		(���� �߰��ؼ� �����)
//===========================================

// �簢�� ���õ� �Լ�
namespace Rect
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
}

namespace Draw
{
	inline void Rect(HDC hdc, RECT rc)
	{
		Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	}

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
}