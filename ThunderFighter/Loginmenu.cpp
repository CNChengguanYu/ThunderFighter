#include "Loginmenu.h"
#include "Regmenu.h"
#include <QPushButton>
Loginmenu::Loginmenu(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	Regmenu* RegMenu = new Regmenu();
	setWindowFlags(Qt::FramelessWindowHint | windowFlags());//设置无边框
	connect(ui.RegBtn, &QPushButton::clicked, this, [=]()		//点击注册按钮
		{
			RegMenu->show();
			this->close();
		});
	connect(RegMenu, &Regmenu::regEnd, this, [=]()				//接受到注册按钮"输入完毕"的信号
		{
			ui.Accline->setText(RegMenu->getInfo(0));
			this->show();
		});
	connect(ui.loginBtn, &QPushButton::clicked, this, [=]()		//点击登录后发生的事
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
		//移到左上角
		move(e->globalPos() - p);
	}
}

void Loginmenu::mousePressEvent(QMouseEvent* e)
{
	if (e->buttons() & Qt::LeftButton)
	{
		//求坐标差值
		p = e->globalPos() - this->frameGeometry().topLeft();
	}
}
