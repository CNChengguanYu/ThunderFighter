#pragma once
#include<QSqlDatabase>
#include<QSqlQuery>
#include <QSqlError>
#include <QObject>
#include <QString>


class DataBaseOperate : public QObject
{
	Q_OBJECT

public:
	bool IsExistJudge(QString input_table,int meta_List,QString input);		//�˺����ж�������ַ����Ƿ��Ѿ�����
																			//�������Ϊ���ҵı����ҵ��ֶ�(�к�)����Ҫ�жϵ��ַ���
																			//����Ѿ������򷵻�1�������򷵻�0
	QString GetRowElement(int meta_List, int key_List,QString input_table,QString key); //�˺������ز�����Ӧ��Ԫ��
																			//����������Ԫ�ص�����---����������---���ҵı�---������ֵ
	void DataBaseInput(int metaNum,QString*Info);
	DataBaseOperate(QObject *parent);
	~DataBaseOperate();
private:
	QSqlDatabase db; //�������ݿ�db	
};
