#ifndef POT_H
#define POT_H

#include "../src/dishes.h"
#include "string"

 using namespace std;
//кружка
class pot : public dishes {
public:
    pot();
    pot(double,bool,string,string);
    string DrinkTea();//уникальная функция выпить чай(если он уже есть в стакане)
    string fill(string,double);//наполнить
    string clean();//почистить
    string use();//употребить
    string name();//имя объекта
    string info(); //информация о объекте
    ~pot();
};


#endif