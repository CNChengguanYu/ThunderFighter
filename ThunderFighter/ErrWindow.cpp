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
	this->setWindowFlags(Qt::WindowCloseButtonHint);//关闭菜单的最小化键
	switch (code)			//不会吧不会吧，不会有人会用枚举吧
	{
	case 0:					//两次输入的密码不一致
		setWindowTitle("密码不一致");
		ui.Errcode->setText("错误代码：0");
		ui.Errinfo->setText("您两次输入的密码不一致");
		this->show();
		break;
	case 1:
		setWindowTitle("输入错误");
		ui.Errcode->setText("错误代码：1");
		ui.Errinfo->setText("您的输入不完整");
		this->show();
		break;
	case 2:
		setWindowTitle("账号已存在");
		ui.Errcode->setText("错误代码：2");
		ui.Errinfo->setText("您输入的账号已存在");
		this->show();
		break;
	default:
		break;
	}
}
