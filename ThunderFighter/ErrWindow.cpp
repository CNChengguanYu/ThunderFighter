#include "ErrWindow.h"
#pragma  execution_character_set("utf-8")	
ErrWindow::ErrWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

ErrWindow::~ErrWindow()
{
}

void ErrWindow::Err(int code)
{
	this->setWindowFlags(Qt::WindowCloseButtonHint);//�رղ˵�����С����
	switch (code)			//����ɲ���ɣ��������˻���ö�ٰ�
	{
	case 0:					//������������벻һ��
		setWindowTitle("���벻һ��");
		ui.Errcode->setText("������룺0");
		ui.Errinfo->setText("��������������벻һ��");
		this->show();
		break;
	case 1:
		setWindowTitle("�������");
		ui.Errcode->setText("������룺1");
		ui.Errinfo->setText("�������벻����");
		this->show();
		break;
	case 2:
		setWindowTitle("�˺��Ѵ���");
		ui.Errcode->setText("������룺2");
		ui.Errinfo->setText("��������˺��Ѵ���");
		this->show();
		break;
	default:
		break;
	}
}
