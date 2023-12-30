#ifndef COOKER_H
#define COOKER_H

#include "dishes.h"
#include "string"

 using namespace std;

class cooker : public dishes //Кастрюля
{
public:
    cooker();
    cooker(double,bool,string,string);
    string cook();//уникальная функция(приготовить что-либо)
    string fill(string,double);//наполнить
    string clean();//почистить
    string use();//употребить
    string name();//имя объекта
    string info(); //информация о объекте
    ~cooker();
};

#endif