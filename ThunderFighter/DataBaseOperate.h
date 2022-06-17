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
	bool IsExistJudge(QString input_table,int meta_List,QString input);		//此函数判断输入的字符串是否已经存在
																			//输入参数为查找的表，查找的字段(列号)，需要判断的字符串
																			//如果已经存在则返回1，不在则返回0
	QString GetRowElement(int meta_List, int key_List,QString input_table,QString key); //此函数返回参数对应的元素
																			//参数：查找元素的列数---主键的列数---查找的表---主键的值
	void DataBaseInput(int metaNum,QString*Info);
	DataBaseOperate(QObject *parent);
	~DataBaseOperate();
private:
	QSqlDatabase db; //创建数据库db	
};
