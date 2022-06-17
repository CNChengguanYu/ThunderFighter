#pragma once
#include <QWidget>
//#include <QWidget>
#include<QMouseEvent>		//���ģ��
#include "ui_Regmenu.h"
#include <QString>
#include "ErrWindow.h"
#include "DataBaseOperate.h"
#include <QPushButton>
#include <QRegExpValidator>    //������ʽ������ͷ�ļ���׼��
#include <QDebug>
class Regmenu : public QWidget
{
	Q_OBJECT

public:
	Regmenu(QWidget *parent = Q_NULLPTR);
	~Regmenu();
	QString getInfo(int Num);
signals:
	void regEnd();//ע������������ź�
private:
	Ui::Regmenu ui;
	QPoint p;	//���ָ��
	QString Info[3];//�洢�˺ţ�����������
	void InSetUp();   //��ʼ�������׼
	bool InfoJudge();//��Ϣ�ö����������ע���ִ�У������ж������Ƿ�Ϸ�
	ErrWindow *ERR=new ErrWindow();
	DataBaseOperate *rob_a = new DataBaseOperate(this);  //ʹ�û�����aΪ���ǿ������ݿ�
protected:
	void mouseMoveEvent(QMouseEvent* e);		//�ƶ�����
	void mousePressEvent(QMouseEvent* e);		//�ƶ�����
};
