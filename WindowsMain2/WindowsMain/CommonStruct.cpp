#include "stdafx.h"
#include "CommonStruct.h"
#include "CommonFunction.h"

RECT CenterRect :: ToRect()
{
	RECT rc = Rect::MakeRect(x - width / 2, y - height / 2, width, height);
	return rc;
}
