#include "dbmanager.h"

DBManager::DBManager()
{

}

DBManager::~DBManager()
{
    delete query;
}

void DBManager::createAutoDB()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./autoDB.db");

    if(db.open())
    {
        qDebug("Open window cpp");
    }
    else
    {
        qDebug("No open window cpp");
    }

    query = new QSqlQuery(db);
    query->exec("CREATE TABLE Auto_details("
                "detail_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                " datail_name varchar(50) not null,"
                " car_brand varchar(30) not null,"
                " car_model varchar(50) not null,"
                " car_year integer not null,"
                " in_stock integer not null,"
                " price float not null, "
                " detail_state varchar(5) not null,"
                " category varchar(30) not null);");
}

//QSqlDatabase DBManager::returnAutoDB()
//{
//    return db;
//}



bool  DBManager::insert(AutoDetail autoDetail)
{
    QString insertQuery = "INSERT INTO Auto_details("
                          "detail_name,"
                          "car_brand,"
                          "car_model,"
                          "car_year,"
                          "in_stock,"
                          "price,"
                          "detail_state,"
                          "category)"
                          "VALUES(?,?,?,?,?,?,?,?);";


    query->prepare(insertQuery);

    query->addBindValue(autoDetail.getName());
    query->addBindValue(autoDetail.getBrand());
    query->addBindValue(autoDetail.getModel());
    query->addBindValue(autoDetail.getYear());
    query->addBindValue(autoDetail.getInStock());
    query->addBindValue(autoDetail.getPrice());
    query->addBindValue(autoDetail.getDetail_state());
    query->addBindValue(autoDetail.getCategory());



    if(!query->exec())
    {
        qDebug()<<"Error entering data";
        return false;
    }
    return true;
}







