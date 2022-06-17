#include "Regmenu.h"
#pragma  execution_character_set("utf-8")	

Regmenu::Regmenu(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | windowFlags());//�����ޱ߿�
	connect(ui.RegBtn, &QPushButton::clicked, this, [=]()			//���ע�ᰴť��Ӧ�÷���ʲô
		{
			if (InfoJudge()) 
			{
				rob_a->DataBaseInput(3, Info);
				emit this->regEnd();
				this->close();
			}

		});
	connect(ui.CloseBtn, &QPushButton::clicked, this, &Regmenu::close);//����رհ�ť�󣬹رյ�ǰ����
	InSetUp();//���������׼
	
}

Regmenu::~Regmenu()
{
}

QString Regmenu::getInfo(int Num)
{
	switch (Num)
	{
	case 0:
		return Info[0];
		break;
	case 1 :
		return Info[1];
		break;
	case 2 :
		return Info[2];
		break;
	default:
		return 0;
		break;
	}
}

void Regmenu::InSetUp()
{
	ui.Accline->setMaxLength(8); //���������λ
	ui.Accline->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));           //  �˺�ע��ֻ�������֣���ĸ�˺�Ϊ����Ա��Ҫ�ֶ����
	ui.Nameline->setMaxLength(8); //���������λ
	ui.Passline->setMaxLength(16); //��������16λ
	ui.Passline->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z0-9<>_]+$"))); //  ��������淶��
	ui.Passline_c->setMaxLength(16); //��������16λ
	ui.Passline_c->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z0-9<>_]+$")));  //  ȷ������
}

bool Regmenu::InfoJudge()
{
	Info[0] = ui.Accline->text();
	Info[1] = ui.Nameline->text();
	Info[2] = ui.Passline->text();
	bool IsExist = rob_a->IsExistJudge("User", 0, Info[0]);
	if (Info[2] != ui.Passline_c->text())
	{
		ERR->Err(0);//�������0  ����˶Դ���
		ui.Passline->setText("");
		ui.Passline_c->setText("");
	}
	else if (Info[0] == "" || Info[1] == "" || Info[2] == "")
	{
		ERR->Err(1);//�������1  ���벻����
	}
	else if (IsExist)
	{
		ERR->Err(2);//�������2  �˺��Ѵ���
		ui.Accline->setText("");
	}else{return 1;}
	return 0;
}

void Regmenu::mouseMoveEvent(QMouseEvent* e)
{
	if (e->buttons() & Qt::LeftButton)
	{
		//�Ƶ����Ͻ�
		move(e->globalPos() - p);
	}
}

void Regmenu::mousePressEvent(QMouseEvent* e)
{
	if (e->buttons() & Qt::LeftButton)
	{
		//�������ֵ
		p = e->globalPos() - this->frameGeometry().topLeft();
	}
}
