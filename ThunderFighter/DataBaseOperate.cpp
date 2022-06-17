#include "DataBaseOperate.h"
#pragma  execution_character_set("utf-8")	
#include <QDebug>
DataBaseOperate::DataBaseOperate(QObject *parent)
	: QObject(parent)
{
	db = QSqlDatabase::addDatabase("QSQLITE");  //数据库类型为"QSQLITE"
	db.setDatabaseName("data.db");				//依次为数据库名，主机名，数据库账号，数据库密码;
	db.setHostName("pc");
	db.setUserName("Admin");
	db.setPassword("123456");
	db.open();									//打开数据库进行操作
	/*----------------------------------------------------------------------创建数据表-----------------------------------------------------------------------*/
	QSqlQuery sql(db);							//连接操作器
						/*---------账号信息表--------*/
	QString UserTableInfo = "CREATE TABLE User(Account integer primary key,\
						Name varchar(16),\
						IsAdmin BOOLEAN,\
						Level int,\
						Password varchar(32))";    //定义了表元素喵。  分别是  INT 账号（主键是唯一的喵）, STRING 学生姓名，BOOL 是/否管理员权限(默认为0喵) ,INT 密码
						/*---------成绩信息表--------*/
	bool IsAddTable = sql.exec(UserTableInfo);	//看看输入是否成功了喵
	if (IsAddTable) { qDebug() << "用户表创建成功了喵OwO"; }
	else { qDebug() << "用户表创建失败了喵(o_ _)ﾉ(。﹏。)"; qDebug() << "好似喵(　^ω^)"; }

	qDebug() << "##########################################################################################";
	qDebug() << "#    如果是第一次启动，会在根目录创建一个data.db的数据库文件，请确该文件存在且可访问!    #";
	qDebug() << "# 如果是第二次以上启动，则数据库创建失败是正常现象！默认账号Admin,密码123456(大小写敏感) #";
	qDebug() << "#	    	               	 可以修改代码关闭cmd输出！                               #";
	qDebug() << "##########################################################################################";
	/*---------------------------------------------------------------------创建数据表------------------------------------------------------------------------*/

}

DataBaseOperate::~DataBaseOperate()
{
}

QString DataBaseOperate::GetRowElement(int meta_List, int key_List, QString input_table, QString key)
{
	QSqlQuery sql(db);
	QString inputTable = QString("select * from %1").arg(input_table);  //打开输入指定的表格
	sql.prepare(inputTable);  //查询表的所有列内容
	if (!sql.exec())					//打不开报错
	{
		qDebug() << sql.lastError();
	}
	else
	{
		while (sql.next())
		{								  //遍历数据库账号的行数列
			QString KeyData = sql.value(key_List).toString();
			QString TableData = sql.value(meta_List).toString();		     //获取该行的列元素
			if (KeyData == key) { return TableData; }

		}
		
	}
	return 0;
}

void DataBaseOperate::DataBaseInput(int metaNum, QString* Info)
{
	QSqlQuery sql(db);

	switch (metaNum)
	{
	case 3:
		{QString exes = QString("INSERT INTO User(Account,Name,IsAdmin,Level,Password) values('%1','%2','%3','%4','%5')").arg(Info[0],Info[1], "0","0", Info[2]);
		sql.exec(exes); }
		break;
	default:
		break;
	}
}

bool DataBaseOperate::IsExistJudge(QString input_table, int meta_List, QString input)   //查找表，查找字段(列号)、查找的字符串
{
	//QSqlDatabase db;
	db.open();
	QSqlQuery sql(db);
	QString inputTable = QString("select * from %1").arg(input_table);  //打开输入的表格
	sql.prepare(inputTable);  //查询表的所有列内容
	if (!sql.exec())					//打不开报错
	{
		qDebug() << sql.lastError();
	}
	else
	{
		while (sql.next())
		{								  //遍历数据库账号的行数列
			//qDebug() << "123";
			//qDebug() << input_table << meta_char << input;
			QString TableData = sql.value(meta_List).toString();		     //获取该行的列元素
			if (TableData == input) { return 1; }
			
		}
		return 0;
	}
	
	
}