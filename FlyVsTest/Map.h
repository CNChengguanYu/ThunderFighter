#pragma once


#include <QObject>

class Map : public QObject
{
	Q_OBJECT

public:
	Map(QObject *parent);
	~Map();

};
