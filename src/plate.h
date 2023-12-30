#ifndef PLATE_H
#define PLATE_H 

#include "../src/dishes.h"

class plate : public dishes //тарелка
{
public:
    plate();
    plate(double,bool,string,string);
    string fly_plate();//уникальный метод
    string fill(string,double);//наполнить
    string clean();//почистить
    string use();//употребить
    string name();//имя объекта
    string info(); //информация о объекте
    ~plate();
};


#endif