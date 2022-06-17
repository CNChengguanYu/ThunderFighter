#pragma  execution_character_set("utf-8")	
#include "FlyVsTest.h"
#include <QDebug>


FlyVsTest::FlyVsTest(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->resize(500,800);
    this->setWindowTitle("����ս��");
    hEro->heroPlane.load(":/FlyVsTest/image/plane.png");
    timer->setInterval(2);                 //���2
    Animatimer->setInterval(5);
    Animatimer->start();
    timer->start();
    int UpSetXYFlag = 200;
    connect(timer, &QTimer::timeout, this, [=]() mutable {              //��������
        
        if (y >= 800){ y = 0;}else{ y++;  } 
        update(); });
    connect(Animatimer, &QTimer::timeout, this, [=]() mutable {         //��ʼ���ɻ�����

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
    painter.drawPixmap(x, y,  pix); //�ڣ�x��y������ʼ�Ŀ�߾�Ϊ50�ľ�������ʾͼƬ
    QPixmap pixb;
    pixb.load(":/FlyVsTest/image/beijing_test1.png");
    painter.drawPixmap(x, y-800, pixb); //�ڣ�x��y������ʼ�Ŀ�߾�Ϊ50�ľ�������ʾͼƬ

    
    painter.drawPixmap(hEro->getHeroX(),hEro->getHeroY(),75,75,hEro->heroPlane);
}

void FlyVsTest::keyPressEvent(QKeyEvent* event)     //���¼��̺�����
{
        if (event->key() == Qt::Key_Left) {//��

            connect(Animatimer, &QTimer::timeout, this, [=]() mutable {
                if (hEro->getHeroX() >= 0) {
                    hEro->setHeroXY(1, hEro->getHeroX() - 2);
                    hEro->heroPlane.load(":/FlyVsTest/image/plane_left.png");
                    update();

                }}, Qt::UniqueConnection);
    } 
    if (event->key() == Qt::Key_Right) {//��
            connect(Animatimer, &QTimer::timeout, this, [=]() mutable {
                if (hEro->getHeroX() <= 425) {
                    hEro->setHeroXY(1, hEro->getHeroX() + 2);
                    hEro->heroPlane.load(":/FlyVsTest/image/plane_right.png");
                    update();
                }
                }, Qt::UniqueConnection);
    }
    if (event->key() == Qt::Key_Up ) {//��
            connect(Animatimer, &QTimer::timeout, this, [=]() mutable {
                if (hEro->getHeroY() >= 0) {
                    hEro->setHeroXY(2, hEro->getHeroY() - 2);
                    update();
                }

                }, Qt::UniqueConnection);
    }
    if (event->key() == Qt::Key_Down) {//��
            connect(Animatimer, &QTimer::timeout, this, [=]() mutable {
                if (hEro->getHeroY() <= 725) {
                    hEro->setHeroXY(2, hEro->getHeroY() + 2);
                    update();
                } }, Qt::UniqueConnection);
    }
}

void FlyVsTest::keyReleaseEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Up) {//�� �����ͷ�
        disconnect(Animatimer, &QTimer::timeout, this, 0);  //�����ͷź󣬶Ͽ�����
    }
    if (event->key() == Qt::Key_Down ) {//�� �����ͷ�
        disconnect(Animatimer, &QTimer::timeout, this, 0);  //�����ͷź󣬶Ͽ�����
    }
    if (event->key() == Qt::Key_Left ) {//�� �����ͷ�
        hEro->heroPlane.load(":/FlyVsTest/image/plane.png");
        update();
        disconnect(Animatimer, &QTimer::timeout, this, 0);  //�����ͷź󣬶Ͽ�����
    }
    if (event->key() == Qt::Key_Right) {//�� �����ͷ�
        hEro->heroPlane.load(":/FlyVsTest/image/plane.png");
        update();
        disconnect(Animatimer, &QTimer::timeout, this, 0);  //�����ͷź󣬶Ͽ�����
    }
}
