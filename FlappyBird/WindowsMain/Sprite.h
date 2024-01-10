#pragma once
#include "ResourceBase.h"

class Texture;
class Sprite : public ResourceBase
{
public:
	Sprite(Texture* texture, int x, int y, int cx, int cy);
	virtual ~Sprite();
public:
	HDC GetDC();
	int32 GetTransparent();
	Vector2Int GetPos() { return Vector2Int(_x, _y); }
	Vector2Int GetSize() { return Vector2Int(_cx, _cy); }

protected:
	Texture* _texture = nullptr;
	int _x;
	int _y;
	int _cx;
	int _cy;
};

