#pragma once
#include "Main.h"

enum eCardShape
{
	SPADE,
	DIA,
	CLOVER,
	HEART
};

enum eCardText
{
	ACE = 1,
	JACK = 10,
	QUEEN,
	KING
};

void PrintCard(int cardNum)
{
	switch (cardNum / 13)
	{
	case eCardShape::SPADE:
		cout << "��";
		break;
	case eCardShape::DIA:
		cout << "��";
		break;
	case eCardShape::CLOVER:
		cout << "��";
		break;
	case eCardShape::HEART:
		cout << "��";
		break;
	default:
		break;
	}

	switch (cardNum % 13 + 1)
	{
	case eCardText::ACE:
		cout << "A";
	case eCardText::JACK:
		cout << "J";
		break;
	case eCardText::QUEEN:
		cout << "Q";
		break;
	case eCardText::KING:
		cout << "K";
		break;
	default:
		cout << cardNum % 13 + 1;
		break;
	}
}