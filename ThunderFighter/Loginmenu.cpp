#include "Loginmenu.h"
#include "Regmenu.h"
#include <QPushButton>
Loginmenu::Loginmenu(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	Regmenu* RegMenu = new Regmenu();
	setWindowFlags(Qt::FramelessWindowHint | windowFlags());//�����ޱ߿�
	connect(ui.RegBtn, &QPushButton::clicked, this, [=]()		//���ע�ᰴť
		{
			RegMenu->show();
			this->close();
		});
	connect(RegMenu, &Regmenu::regEnd, this, [=]()				//���ܵ�ע�ᰴť"�������"���ź�
		{
			ui.Accline->setText(RegMenu->getInfo(0));
			this->show();
		});
	connect(ui.loginBtn, &QPushButton::clicked, this, [=]()		//�����¼��������
		{
			qDebug() << ui.Passline->text() << " |&| " << rob->GetRowElement(4, 0, "User", ui.Accline->text());
			if (ui.Passline->text() == "") { qDebug() << "!!@#$@!@!@"; }else
			if (ui.Passline->text()== rob->GetRowElement(4,0,"User", ui.Accline->text()))
			{
				qDebug() << "!!@";
				emit this->loginEnd();
				this->close();
			}
			
		});
}

Loginmenu::~Loginmenu()
{
}

void Loginmenu::mouseMoveEvent(QMouseEvent* e)
{
	if (e->buttons() & Qt::LeftButton)
	{
		//�Ƶ����Ͻ�
		move(e->globalPos() - p);
	}
}

void Loginmenu::mousePressEvent(QMouseEvent* e)
{
	if (e->buttons() & Qt::LeftButton)
	{
		//�������ֵ
		p = e->globalPos() - this->frameGeometry().topLeft();
	}
}
