#ifndef DISHES_H
#define DISHES_H
#include <string>
#include <iostream>
#include <sstream>

#define zero "пусто"

    using namespace std;

class dishes// Посуда.
{
protected:// Варианты полей: объём, чистая, содержимое, цвет
    double V;
    bool CLEAN;
    string color;
    string content;
// Варианты методов: налить указанный объём указанного содержимого, помыть, выпить
public:
    friend ostream& operator <<(ostream&,dishes&);
    friend istream& operator >>(istream&,dishes&);
    virtual string fill(string,double);//наполнить
    virtual string clean();//почистить
    virtual string use()=0;//употребить
    virtual string name()=0;//имя объекта
    virtual string info()=0; //информация о объекте
    dishes();//коснтруктор с параметрами
    dishes(double,bool,string,string);//конструктор без параметров
    virtual ~dishes(); //диструктор

};

void WaitEnter();
#endif


