#include "addinfo.h"
#include "ui_addinfo.h"

AddInfo::AddInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddInfo)
{
    ui->setupUi(this);
}

AddInfo::~AddInfo()
{
    delete ui;
}

void AddInfo::on_buttonOk_clicked(QAbstractButton *button)
{

}

