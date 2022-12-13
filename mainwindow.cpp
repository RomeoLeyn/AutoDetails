#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);


//    db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("./autoDB.db");

//    if(db.open())
//    {
//        qDebug("Open window cpp");
//    }
//    else
//    {
//        qDebug("No open window cpp");
//    }

//    query = new QSqlQuery(db);
//    query->exec("CREATE TABLE Auto_details("
//                "detail_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
//                " datail_name varchar(50) not null,"
//                " car_brand varchar(30) not null,"
//                " car_model varchar(50) not null,"
//                " car_year integer not null,"
//                " in_stock integer not null,"
//                " price float not null, "
//                " detail_state varchar(5) not null,"
//                " category varchar(30) not null);");

    dataBase.createAutoDB();

    model = new QSqlTableModel(this,db);
    model->setTable("Auto_details");
    model->select();

    ui->tableView->setModel(model);

    viewOfTable();

    //    ui->categoryBox->addItem("Двигун",QVariant(1));
    //    ui->categoryBox->addItem("Підвіска",QVariant(2));
    //    ui->categoryBox->addItem("Кузов",QVariant(3));
    //    ui->categoryBox->addItem("Трансмісія",QVariant(4));
    //    ui->categoryBox->addItem("Електрика",QVariant(5));
    //    ui->categoryBox->addItem("Гальмівна система",QVariant(6));
    //    ui->categoryBox->addItem("ТО",QVariant(7));
    //    ui->categoryBox->addItem("Рульова система",QVariant(8));
    //    ui->categoryBox->addItem("Система охолодження",QVariant(9));
    //    ui->categoryBox->addItem("Фільтри",QVariant(10));
    //    ui->categoryBox->addItem("Шасі",QVariant(11));
    //    connect(ui->categoryBox,&QComboBox::currentIndexChanged,this,&MainWindow::setCategoryBox);//конект для пошуку за категорією

    this->setCategoryItems();
    this->setCarBrandItems();


    ui->resfreshButton->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete addWindow;
}

void MainWindow::setCategoryBox(int index)
{
    this->categoryBoxIndex = index;
}

void MainWindow::setCategoryItems()
{
    ui->categoryBox->addItem("",QVariant(0));
    ui->categoryBox->addItem("Двигун",QVariant(1));
    ui->categoryBox->addItem("Підвіска",QVariant(2));
    ui->categoryBox->addItem("Кузов",QVariant(3));
    ui->categoryBox->addItem("Трансмісія",QVariant(4));
    ui->categoryBox->addItem("Електрика",QVariant(5));
    ui->categoryBox->addItem("Гальмівна система",QVariant(6));
    ui->categoryBox->addItem("ТО",QVariant(7));
    ui->categoryBox->addItem("Рульова система",QVariant(8));
    ui->categoryBox->addItem("Система охолодження",QVariant(9));
    ui->categoryBox->addItem("Фільтри",QVariant(10));
    ui->categoryBox->addItem("Шасі",QVariant(11));
    connect(ui->categoryBox,&QComboBox::currentIndexChanged,this,&MainWindow::setCategoryBox);//конект для пошуку за категорією
}

void MainWindow::setCarBrandBox(int index)
{
    this->carBrandIndex = index;
}

void MainWindow::setCarBrandItems()
{
    ui->carBrandBox->addItem("",QVariant(0));
    ui->carBrandBox->addItem("Мерседес",QVariant(1));
    ui->carBrandBox->addItem("Део",QVariant(2));
    ui->carBrandBox->addItem("Бмв",QVariant(3));
    ui->carBrandBox->addItem("Інфініті",QVariant(4));
    ui->carBrandBox->addItem("Фольцваген",QVariant(5));
    ui->carBrandBox->addItem("Тойота",QVariant(6));
    ui->carBrandBox->addItem("Опель",QVariant(7));
    ui->carBrandBox->addItem("Рено",QVariant(8));
    ui->carBrandBox->addItem("Хюндай",QVariant(9));
    ui->carBrandBox->addItem("Фіат",QVariant(10));
    ui->carBrandBox->addItem("Шевроле",QVariant(11));
    ui->carBrandBox->addItem("Субару",QVariant(12));
    connect(ui->carBrandBox,&QComboBox::currentIndexChanged,this,&MainWindow::setCarBrandBox);
}

void MainWindow::on_addButton_clicked()
{
    addWindow = new ClassAdd;
    addWindow->open();
    addWindow->exec();
    model->select();

    ui->tableView->setModel(model);
}

void MainWindow::viewOfTable()
{
    ui->tableView->hideColumn(0);
}

void MainWindow::on_deleteButton_clicked()
{

    QMessageBox::StandardButton deleterow;

    deleterow = QMessageBox::question(this, "Тест", "Ви дійсно хочете видалити дані?",
                                      QMessageBox::Yes|QMessageBox::Cancel);

    if (deleterow == QMessageBox::Yes)
    {
        model->removeRow(row);
        model->select();
    }
    if (deleterow == QMessageBox::Cancel)
    {

    }
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

void MainWindow::on_SearchButton_clicked()
{
    this->categoryToSearch=ui->categoryBox->itemText(categoryBoxIndex);

    this->carBrandToSearch=ui->carBrandBox->itemText(carBrandIndex);

    QString queryToSearch="select * from Auto_details where category = '"+categoryToSearch+"' and car_brand = '"+carBrandToSearch+"';";
    QSqlQueryModel * modal = new QSqlQueryModel();
    query->exec();
    modal->setQuery(queryToSearch);
    ui->tableView->setModel(modal);
    ui->resfreshButton->show();
}

//void MainWindow::on_carSearchButton_clicked()
//{
//    this->carBrandToSearch=ui->carBrandBox->itemText(carBrandIndex);

//    QString queryToSearch="select * from Auto_details where car_brand = '"+carBrandToSearch+"';";
//    QSqlQueryModel * modal = new QSqlQueryModel();
//    query->exec();
//    modal->setQuery(queryToSearch);
//    ui->tableView->setModel(modal);
//    ui->resfreshButton->show();
//}

void MainWindow::on_resfreshButton_clicked()
{
    model->select();
    ui->tableView->setModel(model);
    ui->resfreshButton->hide();
}


void MainWindow::on_exitButton_clicked()
{
    QApplication::exit();
}


