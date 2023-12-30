#include "pot.h"

pot::pot():dishes::dishes()
{}

pot::pot(double a,bool g,string b,string c):dishes::dishes(a,g,b,c)
{}

string pot::clean()
{
    string str;
    if (CLEAN) str="Она чистая.Зачем????";
    else 
    {
        str="Вы помыли кружку";
        if (V>0)
            {
                cout<<" вместе с "<<
                str.insert(str.length(),content);
                str.insert(str.length(),".");
            }
        else str.insert(str.length(),"."); 
        str.insert(str.length(), dishes::clean());
    }
    return str;
}

string pot:: name()
{
    return"Кружка\n";
}

string pot::info()
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

string pot :: DrinkTea()
    {
        string str;   
        if (content=="tea" || content=="Tea") 
        {
            str="Вы выпили чай.Кружка теперь грязная.\n";
            dishes::use();
        }
        else if (content!=zero) 
        {
            str.insert(str.length(),"У вас в кружке уже есть ");
            str.insert(str.length(),content);
            str.insert(str.length(),". \nПомойте кружку и наполните ее чаем.\n");
        }
        else if (!CLEAN) str.insert(str.length(),"Помойте кружку, она грязная, и наполните кружку чаем.");
        else str.insert(str.length(),"\nНаполните кружку чаем.");
        return str;
    }
    
    string pot :: fill(string cont,double v)
    {
        string str;

            str.insert(str.length(),"Теперь у вас в кружке ");
            str.insert(str.length(),cont);
            str.insert(str.length(),".\n");
            str.insert(str.length(),dishes::fill(cont,v));
            return str; 
        
    }

    string pot :: use()//употребить
    {
        string str;
        if (content==zero)
            {            
                str="В кружке";
                str.insert(str.length(),content);
                str.insert(str.length(),".");
            }
        else 
        {
            str.insert(str.length(),"Вы употребили ");
            str.insert(str.length(),content);
            str.insert(str.length(),".Теперь кружка грязная");
            dishes::use(); 
        }
        return str;
    }

    pot::~pot(){}