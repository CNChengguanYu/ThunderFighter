#pragma once
#include<QMouseEvent>		//���ģ��
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
	void loginEnd();//���͵�¼����ź�
private:
	Ui::Loginmenu ui;
	QPoint p;	//���ָ��
	DataBaseOperate *rob=new DataBaseOperate(this);

protected:
	void mouseMoveEvent(QMouseEvent* e);		//�ƶ�����
	void mousePressEvent(QMouseEvent* e);		//�ƶ�����
};
