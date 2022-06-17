#include "Regmenu.h"
#pragma  execution_character_set("utf-8")	

Regmenu::Regmenu(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint | windowFlags());//设置无边框
	connect(ui.RegBtn, &QPushButton::clicked, this, [=]()			//点击注册按钮后，应该发生什么
		{
			if (InfoJudge()) 
			{
				rob_a->DataBaseInput(3, Info);
				emit this->regEnd();
				this->close();
			}

		});
	connect(ui.CloseBtn, &QPushButton::clicked, this, &Regmenu::close);//点击关闭按钮后，关闭当前窗口
	InSetUp();//设置输入标准
	
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
	ui.Accline->setMaxLength(8); //限制输入八位
	ui.Accline->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));           //  账号注册只允许数字，字母账号为管理员需要手动添加
	ui.Nameline->setMaxLength(8); //限制输入八位
	ui.Passline->setMaxLength(16); //限制输入16位
	ui.Passline->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z0-9<>_]+$"))); //  密码输入规范化
	ui.Passline_c->setMaxLength(16); //限制输入16位
	ui.Passline_c->setValidator(new QRegExpValidator(QRegExp("[a-zA-Z0-9<>_]+$")));  //  确认密码
}

bool Regmenu::InfoJudge()
{
	Info[0] = ui.Accline->text();
	Info[1] = ui.Nameline->text();
	Info[2] = ui.Passline->text();
	bool IsExist = rob_a->IsExistJudge("User", 0, Info[0]);
	if (Info[2] != ui.Passline_c->text())
	{
		ERR->Err(0);//错误代码0  密码核对错误
		ui.Passline->setText("");
		ui.Passline_c->setText("");
	}
	else if (Info[0] == "" || Info[1] == "" || Info[2] == "")
	{
		ERR->Err(1);//错误代码1  输入不完整
	}
	else if (IsExist)
	{
		ERR->Err(2);//错误代码2  账号已存在
		ui.Accline->setText("");
	}else{return 1;}
	return 0;
}

void Regmenu::mouseMoveEvent(QMouseEvent* e)
{
	if (e->buttons() & Qt::LeftButton)
	{
		//移到左上角
		move(e->globalPos() - p);
	}
}

void Regmenu::mousePressEvent(QMouseEvent* e)
{
	if (e->buttons() & Qt::LeftButton)
	{
		//求坐标差值
		p = e->globalPos() - this->frameGeometry().topLeft();
	}
}
