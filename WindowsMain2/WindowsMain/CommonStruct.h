#pragma once
struct CenterRect
{
	int x, y, width, height;

	RECT ToRect()
	{
		RECT rc;
		Rect::MakeRect(x - width / 2, y - height / 2, width, height);
		return rc;
	}
};