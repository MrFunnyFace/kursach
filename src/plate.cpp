#include "plate.h"

plate::plate():dishes::dishes()
{}

plate::plate(double a,bool g,string b,string c):dishes::dishes(a,g,b,c)
{}

string plate::clean()
{
    string str;
    if (CLEAN) str="Она чистая.Зачем????";
    else 
    {
        if (content!=zero)
        {        
            str="Вам пришлось вылить ";
            str.insert(str.length(), content);
            str.insert(str.length(),"."); 
        }
        else cout<<"."<<endl;
        dishes::clean();
        str="Вы помыли тарелку.";
    }
    return str;
}

string plate:: name()
{
    return "Тарелка\n";
}

string plate::info()
{
    string str;
    str.insert(str.length(),name());
    str.insert(str.length() ,"\nОбъем: ");
    std::stringstream ss;
    ss<<V;
    string c;
    ss>>c;
    str.insert(str.length(),c);
    if(CLEAN) str.insert(str.length() ,"\nЧистота: чистое");
    else str.insert(str.length() ,"\nЧистота: не истое");
    str.insert(str.length(), "\nЦвет: ");
    str.insert(str.length(), color);
    str.insert(str.length(), "\nСодержимое: ");
    str.insert(str.length(), content);
    return str;
}

string plate :: fly_plate()
    {
        string str;
        str="Просто тарелка взлетела и улетела.";
        str.insert(str.length(),"_-\n -\n  -\n   -\n  -\n -\n_-\n");
        str.insert(str.length(),"Тарелка прилетела");
        return str;
    }
    
   string plate :: fill(string cont,double v)
    {
        string str;
        if (content!=zero) 
        {
            str.insert(str.length(), "В тарелке уже есть ");
            str.insert(str.length(), content);
            str.insert(str.length(), ". Пришлось вылить/выкинуть.\n");
        }
        else if (!CLEAN) str.insert(str.length(), "Я не советую есть из грязной тарелки(-_-').\n");
        str.insert(str.length(), dishes::fill(cont,v));
        return str;

    }

    string plate :: use()
    {
        string str;
        if (CLEAN) str="В тарелке пусто.";
        else if (content!=zero) 
        {
            str="В кастрюле ";
            str.insert(str.length(),content);
            str.insert(str.length(),".");
        }
        else 
        {
            dishes::use(); 
            str="Вы съели/выпили все что было в тарелке.Теперь она грязная";
        }
        return str;
    }

    plate::~plate(){}