#pragma once
#include "Heroplane.h"
#include <QtWidgets/QMainWindow>
#include "ui_FlyVsTest.h"
#include <QPixmap>
#include <QPainter>
#include <Qpen>
#include <QKeyEvent>	//	键盘处理库
#include <QTimer>
class FlyVsTest : public QMainWindow
{
	Q_OBJECT

public:
	FlyVsTest(QWidget *parent = Q_NULLPTR);
	void paintEvent(QPaintEvent*);
signals:
	void Key_x_left();
	void Key_x_right();
	void Key_y_left();
	void Key_y_right();
private:
	Ui::FlyVsTestClass ui;
	int x = 0, y = 0;
	Heroplane* hEro = new Heroplane(this);
	void keyPressEvent(QKeyEvent* event);
	void keyReleaseEvent(QKeyEvent* event);
	QTimer* timer = new QTimer(this);       //设置定时器
	QTimer* Animatimer = new QTimer(this);       //设置定时器

};
