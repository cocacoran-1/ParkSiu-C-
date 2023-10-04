#include "stdafx.h"
#include "CommonStruct.h"
#include "CommonFunction.h"

RECT CenterRect::ToRect()
{
	RECT rc = Rect::MakeRect(static_cast<int>(x - width / 2), static_cast<int>(y - height / 2), static_cast<int>(width), static_cast<int>(height));

	return rc;
}
Gdiplus::Rect CenterRect::ToGdiRect()
{
	Gdiplus::Rect rc = Gdiplus::Rect(static_cast<int>(x - width / 2), static_cast<int>(y - height / 2), static_cast<int>(width), static_cast<int>(height));

	return rc;
}

CenterRect CenterRect::FromRect(RECT rect)
{
	CenterRect centerRect = {};
	centerRect.x = static_cast<float>((rect.left + rect.right) / 2);
		// rect.left + (rect.right - rect.left) / 2;
	centerRect.y = static_cast<float>((rect.top + rect.bottom) / 2);
		// rect.top + (rect.bottom -rect.top) / 2;
	centerRect.width = static_cast<float>(rect.right - rect.left);
	centerRect.height = static_cast<float>(rect.bottom - rect.top);

	return centerRect;
}
