#ifndef CLASSADD_H
#define CLASSADD_H

#include <QDialog>
#include<qstring.h>
//#include<mainwindow.h>
#include<QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlTableModel>
#include<QComboBox>

#include"dbmanager.h"

namespace Ui {
class ClassAdd;
}

class ClassAdd : public QDialog
{
    Q_OBJECT

public:
    explicit ClassAdd(QWidget *parent = nullptr);
    ~ClassAdd();

private slots:
    void on_buttonOk_clicked();

    //void on_buttonDecline_clicked();

    void setComboBox(int index);

    void setStateBox(int index);

    void setStateItems();

private:
    Ui::ClassAdd *ui;

    QString name;
    QString brand;
    QString model;
    int year;
    int in_Stock;
    float price;
    QString detail_state;
    QString category;

    DBManager dataBase;

    QSqlDatabase db;
    QSqlQuery *query;
    //QSqlTableModel *model;

    int ComboBoxIndex;

    int stateBoxIndex;


};

#endif // CLASSADD_H
