#pragma once
#include<QMouseEvent>		//鼠标模块
#include <QWidget>
#include "ui_Loginmenu.h"
#include "DataBaseOperate.h"
class Loginmenu : public QWidget
{
	Q_OBJECT

public:
	Loginmenu(QWidget *parent = Q_NULLPTR);
	~Loginmenu();
signals:
	void loginEnd();//发送登录完毕信号
private:
	Ui::Loginmenu ui;
	QPoint p;	//鼠标指针
	DataBaseOperate *rob=new DataBaseOperate(this);

protected:
	void mouseMoveEvent(QMouseEvent* e);		//移动窗口
	void mousePressEvent(QMouseEvent* e);		//移动窗口
};
