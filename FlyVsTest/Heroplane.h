#pragma once
#include<QPixmap>
#include <QObject>

class Heroplane : public QObject
{
	Q_OBJECT

public:
	Heroplane(QObject *parent);
	~Heroplane();
	int getHeroX();
	int getHeroY();
	void setHeroXY(int cOde, int inNum);  //����������޸ĵ��� 1-x��2-y
	QPixmap heroPlane;
	void UpSetXY();
private:
	int heroX = 212;
	int heroY = 800;
	
};
