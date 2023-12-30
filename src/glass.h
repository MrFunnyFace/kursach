#ifndef GLASS_H
#define GLASS_H

#include "dishes.h"
#include "string"

 using namespace std;


class glass : public dishes //стакан
{
public:    
    glass();
    glass(double,bool,string,string);
    string fill(string,double);//наполнить
    string clean();//почистить
    string use();//употребить
    string name();//имя объекта
    string info(); //информация о объекте
    ~glass();
    string broke();//уникальный метод разбить стакан(в прямом смысле уничтожить его)
};

#endif