#pragma once
#include "GdiplusSpriteActor.h"
class ItemBox : public GdiplusSpriteActor
{
private:
	ItemBoxType _itemBoxType;

public:
	void SetItemBoxInfo(ItemBoxType type, CenterRect body);
public:
	using Super = GdiplusSpriteActor;
public:
	virtual void Init() override;
	virtual void Render(HDC hdc) override;
	virtual void Update() override;
	virtual void Release() override;

public:
	virtual void OnComponentBeginOverlap(Collider* collider, Collider* other) override;
	virtual void OnComponentEndOverlap(Collider* collider, Collider* other) override;
};

