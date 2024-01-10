#include "stdafx.h"
#include "ItemBox.h"

void ItemBox::Init()
{
	//�θ�Ŭ���� �⺻���� ó��
	Super::Init();

	this->SetName("ItemBox");

}
void ItemBox::Render(HDC hdc)
{
	if (_isActive == false) return;
	//�θ�Ŭ���� �⺻���� ó��
	Super::Render(hdc);

}
void ItemBox::Update()
{
	if (_isActive == false) return;
	//�θ�Ŭ���� �⺻���� ó��
	Super::Update();

}
void ItemBox::Release()
{
	//�θ�Ŭ���� �⺻���� ó��
	Super::Release();

}

void ItemBox::OnComponentBeginOverlap(Collider* collider, Collider* other)
{

}

void ItemBox::OnComponentEndOverlap(Collider* collider, Collider* other)
{
}

void ItemBox::SetItemBoxInfo(ItemBoxType type, CenterRect body)
{
	_itemBoxType = type;

	switch (_itemBoxType)
	{
	case ItemBoxType::None:
		break;
	case ItemBoxType::HpItemBox:
		this->SetSprite(L"../Resources/Items/hp_item_box.png", body);
		break;
	case ItemBoxType::MissileItemBox:
		this->SetSprite(L"../Resources/Items/missile_item_box.png", body);
		break;
	default:
		break;
	}
}