#pragma once
#include "ResourceBase.h"

struct FlipbookInfo
{
	Texture* texture = nullptr;
	Vector2Int size = {};
	int start = 0;
	int end = 0;
	int line = 0;
	float duration = 1.f;
	bool loop = true;
};

class Flipbook : public ResourceBase
{
protected:
	FlipbookInfo _info = {};

public:
	Flipbook();
	virtual ~Flipbook();

public:
	void SetInfo(const FlipbookInfo& info) { _info = info; }
	const FlipbookInfo& GetInfo() { return _info; }
};

