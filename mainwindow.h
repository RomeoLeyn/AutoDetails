#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QSqlDatabase>
#include<QDebug>
#include<QSqlQuery>
#include<QSqlTableModel>
#include <QComboBox>
#include<QSqlQueryModel >

#include"classadd.h"
#include"dbmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_deleteButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    //void on_infoOfProgram_clicked();

    void on_addButton_clicked();

    void viewOfTable();

    void setCategoryBox(int index);

    void setCategoryItems();

    void setCarBrandBox(int index);

    void setCarBrandItems();

    void on_SearchButton_clicked();

    //void on_textEdit_copyAvailable(bool b);

    void on_resfreshButton_clicked();

    void on_exitButton_clicked();





    //void on_carSearchButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    ClassAdd *addWindow;

    DBManager dataBase;

    QString categoryToSearch;
    QString carBrandToSearch;
    int categoryBoxIndex;
    int carBrandIndex;
    int row;



};
#endif // MAINWINDOW_H
