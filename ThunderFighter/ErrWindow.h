#pragma once

#include <QWidget>
#include "ui_ErrWindow.h"

class ErrWindow : public QWidget
{
	Q_OBJECT

public:
	ErrWindow(QWidget *parent = Q_NULLPTR);
	~ErrWindow();
	void Err(int code);
private:
	Ui::ErrWindow ui;
};
