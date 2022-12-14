#include "autodetail.h"

AutoDetail::AutoDetail()
{

}

QString AutoDetail::getName()
{
    return name;
}

QString AutoDetail::getBrand()
{
    return brand;
}

QString AutoDetail::getModel()
{
    return model;
}

int AutoDetail::getYear()
{
    return year;
}

int AutoDetail::getInStock()
{
    return inStock;
}

float AutoDetail::getPrice()
{
    return price;
}

QString AutoDetail::getDetail_state()
{
    return detailState;
}

QString AutoDetail::getCategory()
{
    return category;
}

void AutoDetail::setName(QString name)
{
    this->name=name;
}

void AutoDetail::setBrand(QString brand)
{
    this->brand=brand;
}

void AutoDetail::setModel(QString model)
{
    this->model=model;
}

void AutoDetail::setYear(int year)
{
    this->year=year;
}

void AutoDetail::setInStock(int inStock)
{
    this->inStock=inStock;
}

void AutoDetail::setPrice(float price)
{
    this->price=price;
}

void AutoDetail::setDetailState(QString detailSstate)
{
    this->detailState=detailSstate;
}

void AutoDetail::setCategory(QString category)
{
    this->category=category;
}
