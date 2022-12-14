#include "classadd.h"
#include "ui_classadd.h"


ClassAdd::ClassAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClassAdd)
{
    ui->setupUi(this);
    //connect(ClassAdd::hide,&QPushButton::clicked,this,&MainWindow::insertInfo);
//    db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName("./autoDB.db");

//    query = new QSqlQuery(db);


//    if(db.open())
//    {
//        qDebug("Open class add");
//    }
//    else
//    {
//        qDebug("No open class ad");
//    }

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
    connect(ui->categoryBox,&QComboBox::currentIndexChanged,this,&ClassAdd::setComboBox);

    this->setStateItems();

}

ClassAdd::~ClassAdd()
{
    delete ui;
}

void ClassAdd::on_buttonOk_clicked()
{
    AutoDetail autoDetail;
    autoDetail.setName(ui->nameEdit->text());
    autoDetail.setBrand(ui->carBrandEdit->text());
    autoDetail.setModel(ui->carModelEdit->text());
    autoDetail.setYear(ui->carYearEdit->text().toInt());
    autoDetail.setInStock(ui->inStockEdit->text().toInt());
    autoDetail.setPrice(ui->priceEdit->text().toDouble());
    autoDetail.setDetailState(ui->stateBox->itemText(stateBoxIndex));
    autoDetail.setCategory(ui->categoryBox->itemText(ComboBoxIndex));


//    QString insertQuery = "INSERT INTO Auto_details("
//                          "detail_name,"
//                          "car_brand,"
//                          "car_model,"
//                          "car_year,"
//                          "in_stock,"
//                          "price,"
//                          "detail_state,"
//                          "category)"
//                          "VALUES(?,?,?,?,?,?,?,?);";


//    query->prepare(insertQuery);

//    query->addBindValue(name);
//    query->addBindValue(brand);
//    query->addBindValue(model);
//    query->addBindValue(year);
//    query->addBindValue(in_Stock);
//    query->addBindValue(price);
//    query->addBindValue(detail_state);
//    query->addBindValue(category);

//    qDebug()<<detail_state;

//    if(!query->exec())
//    {
//        qDebug()<<"Error entering data";
//    }

//    else
//    {
//        qDebug()<<"Succses";
//        this->close();
//    }



   dataBase.insert(autoDetail);
}


void ClassAdd::setComboBox(int index)
{
    this->ComboBoxIndex = index;
}

void ClassAdd::setStateBox(int index)
{
    this->stateBoxIndex = index;
}

void ClassAdd::setStateItems()
{
    ui->stateBox->addItem("",QVariant(0));
    ui->stateBox->addItem("Новий",QVariant(1));
    ui->stateBox->addItem("б/у",QVariant(2));

    connect(ui->stateBox,&QComboBox::currentIndexChanged,this,&ClassAdd::setStateBox);
}


