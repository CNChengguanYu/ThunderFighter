#include "ThunderFighter.h"

ThunderFighter::ThunderFighter(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	LoginMenu->show();
	connect(LoginMenu, &Loginmenu::loginEnd, this, &ThunderFighter::show);
}
