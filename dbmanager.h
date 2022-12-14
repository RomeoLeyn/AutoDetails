#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase> // бібліотека бази даних
#include <QDebug> //бібліотека для відладки програми
#include <QSqlQuery> // бібліотека для запиту до баз даних
#include <QtSql>

#include "autodetail.h"

class DBManager
{

    QSqlDatabase db;
    QSqlQuery *query;

public:
    DBManager();
    ~DBManager();

    void createAutoDB();

    QString getAutoTable();

//    QSqlDatabase returnAutoDB();

    //bool insert(QString &name, QString &brand, QString &model, int &year, int &in_Stock, float &price, QString &detail_state, QString &category) const;

    bool insert(AutoDetail autoDetail);


};

#endif // DBMANAGER_H
