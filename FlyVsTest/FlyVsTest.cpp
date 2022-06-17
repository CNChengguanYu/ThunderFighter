#pragma  execution_character_set("utf-8")	
#include "FlyVsTest.h"
#include <QDebug>


FlyVsTest::FlyVsTest(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->resize(500,800);
    this->setWindowTitle("雷霆战机");
    hEro->heroPlane.load(":/FlyVsTest/image/plane.png");
    timer->setInterval(2);                 //间隔2
    Animatimer->setInterval(5);
    Animatimer->start();
    timer->start();
    int UpSetXYFlag = 200;
    connect(timer, &QTimer::timeout, this, [=]() mutable {              //背景滚动
        
        if (y >= 800){ y = 0;}else{ y++;  } 
        update(); });
    connect(Animatimer, &QTimer::timeout, this, [=]() mutable {         //初始化飞机动画

        if (UpSetXYFlag >= 1)
        {
            hEro->setHeroXY(2, hEro->getHeroY() - 1);
            UpSetXYFlag--;
        }
        update(); });
}

void FlyVsTest::paintEvent(QPaintEvent*)
{
     


    QPainter painter(this);
    QPixmap pix;
    pix.load(":/FlyVsTest/image/beijing_test1.png");
    painter.drawPixmap(x, y,  pix); //在（x，y）点起始的宽高均为50的句型中显示图片
    QPixmap pixb;
    pixb.load(":/FlyVsTest/image/beijing_test1.png");
    painter.drawPixmap(x, y-800, pixb); //在（x，y）点起始的宽高均为50的句型中显示图片

    
    painter.drawPixmap(hEro->getHeroX(),hEro->getHeroY(),75,75,hEro->heroPlane);
}

void FlyVsTest::keyPressEvent(QKeyEvent* event)     //按下键盘后发生的
{
        if (event->key() == Qt::Key_Left) {//左

            connect(Animatimer, &QTimer::timeout, this, [=]() mutable {
                if (hEro->getHeroX() >= 0) {
                    hEro->setHeroXY(1, hEro->getHeroX() - 2);
                    hEro->heroPlane.load(":/FlyVsTest/image/plane_left.png");
                    update();

                }}, Qt::UniqueConnection);
    } 
    if (event->key() == Qt::Key_Right) {//右
            connect(Animatimer, &QTimer::timeout, this, [=]() mutable {
                if (hEro->getHeroX() <= 425) {
                    hEro->setHeroXY(1, hEro->getHeroX() + 2);
                    hEro->heroPlane.load(":/FlyVsTest/image/plane_right.png");
                    update();
                }
                }, Qt::UniqueConnection);
    }
    if (event->key() == Qt::Key_Up ) {//上
            connect(Animatimer, &QTimer::timeout, this, [=]() mutable {
                if (hEro->getHeroY() >= 0) {
                    hEro->setHeroXY(2, hEro->getHeroY() - 2);
                    update();
                }

                }, Qt::UniqueConnection);
    }
    if (event->key() == Qt::Key_Down) {//下
            connect(Animatimer, &QTimer::timeout, this, [=]() mutable {
                if (hEro->getHeroY() <= 725) {
                    hEro->setHeroXY(2, hEro->getHeroY() + 2);
                    update();
                } }, Qt::UniqueConnection);
    }
}

void FlyVsTest::keyReleaseEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Up) {//上 按键释放
        disconnect(Animatimer, &QTimer::timeout, this, 0);  //按键释放后，断开连接
    }
    if (event->key() == Qt::Key_Down ) {//下 按键释放
        disconnect(Animatimer, &QTimer::timeout, this, 0);  //按键释放后，断开连接
    }
    if (event->key() == Qt::Key_Left ) {//左 按键释放
        hEro->heroPlane.load(":/FlyVsTest/image/plane.png");
        update();
        disconnect(Animatimer, &QTimer::timeout, this, 0);  //按键释放后，断开连接
    }
    if (event->key() == Qt::Key_Right) {//右 按键释放
        hEro->heroPlane.load(":/FlyVsTest/image/plane.png");
        update();
        disconnect(Animatimer, &QTimer::timeout, this, 0);  //按键释放后，断开连接
    }
}
