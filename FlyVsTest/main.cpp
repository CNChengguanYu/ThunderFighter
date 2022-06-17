#include "FlyVsTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	FlyVsTest w;
	w.show();
	return a.exec();
}
