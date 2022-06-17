#pragma once
#include"Loginmenu.h"
#include <QtWidgets/QWidget>
#include "ui_ThunderFighter.h"

class ThunderFighter : public QWidget
{
	Q_OBJECT

public:
	ThunderFighter(QWidget *parent = Q_NULLPTR);
	Loginmenu* LoginMenu = new Loginmenu();
private:
	Ui::ThunderFighterClass ui;
};
