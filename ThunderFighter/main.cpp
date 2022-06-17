#include "ThunderFighter.h"
#include "Loginmenu.h"
#include "Regmenu.h"
#include <QtWidgets/QApplication>
#include "DataBaseOperate.h"
#include <QDebug>
#pragma  execution_character_set("utf-8")	
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ThunderFighter w;
	//Loginmenu l;
	//l.show();
	//w.show();

	return a.exec();
}
