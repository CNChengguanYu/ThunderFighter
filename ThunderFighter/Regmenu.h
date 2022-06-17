#pragma once
#include <QWidget>
//#include <QWidget>
#include<QMouseEvent>		//鼠标模块
#include "ui_Regmenu.h"
#include <QString>
#include "ErrWindow.h"
#include "DataBaseOperate.h"
#include <QPushButton>
#include <QRegExpValidator>    //正则表达式，输入头文件标准化
#include <QDebug>
class Regmenu : public QWidget
{
	Q_OBJECT

public:
	Regmenu(QWidget *parent = Q_NULLPTR);
	~Regmenu();
	QString getInfo(int Num);
signals:
	void regEnd();//注册结束，发出信号
private:
	Ui::Regmenu ui;
	QPoint p;	//鼠标指针
	QString Info[3];//存储账号，姓名，密码
	void InSetUp();   //初始化输入标准
	bool InfoJudge();//信息裁定函数，点击注册后执行，负责判断输入是否合法
	ErrWindow *ERR=new ErrWindow();
	DataBaseOperate *rob_a = new DataBaseOperate(this);  //使用机器人a为我们控制数据库
protected:
	void mouseMoveEvent(QMouseEvent* e);		//移动窗口
	void mousePressEvent(QMouseEvent* e);		//移动窗口
};
