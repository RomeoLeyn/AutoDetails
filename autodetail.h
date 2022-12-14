#ifndef AUTODETAIL_H
#define AUTODETAIL_H

#include<QString>
class AutoDetail
{
private:
    QString name;
    QString brand;
    QString model;
    int year;
    int inStock;
    float price;
    QString detailState;
    QString category;

public:
    AutoDetail();



    QString getName();
    QString getBrand();
    QString getModel();
    int getYear();
    int getInStock();
    float getPrice();
    QString getDetail_state();
    QString getCategory();


    void setName(QString name);
    void setBrand(QString brand);
    void setModel(QString model);
    void setYear(int year);
    void setInStock(int inStock);
    void setPrice(float price);
    void setDetailState(QString detailSstate);
    void setCategory(QString category);

};

#endif // AUTODETAIL_H
