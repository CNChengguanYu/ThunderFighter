#include "Heroplane.h"

Heroplane::Heroplane(QObject *parent)
	: QObject(parent)
{
}

Heroplane::~Heroplane()
{
}

int Heroplane::getHeroX()
{
	return heroX;
}

int Heroplane::getHeroY()
{
	return heroY;
}

void Heroplane::setHeroXY(int cOde, int inNum)
{
	switch (cOde)
	{
	case 1:
		heroX = inNum;
		break;
	case 2:
		heroY = inNum;
		break;
	default:
		break;
	}
}

void Heroplane::UpSetXY()
{
	for (int i =0;i<200;i++) 
	{
		heroY--;
	}
}

