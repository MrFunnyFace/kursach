#include "../src/glass.h"

#include "../src/cooker.h"

glass::glass():dishes::dishes()
{}

glass::glass(double a,bool g,string b,string c):dishes::dishes(a,g,b,c)
{}

string glass::clean()
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
        dishes::clean();
        str="Вы помыли стакан.";
    }
    return str;
}

string glass:: name()
{
    return "Стакан\n";
}

string glass::info()
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

string glass :: broke()
    {
        string str;
        str="А зачем?\n";
        str.insert( str.length() ,"Стакан ушел в небытие(ಥ﹏ಥ)\n");
        return str;;
    }
    
string glass :: fill(string cont,double v)
    {
        string str;
        if (content!=zero) 
        {
            str.insert(str.length(), "Пришлось вылить содержимое стакана (");
            str.insert(str.length(), content);
            str.insert(str.length(), ").\n");
        }
        else if (!CLEAN) str.insert(str.length(), "Стакан грязный(Х_Х),не думаю что стоит из него пить.\n");
        dishes::fill(cont,v);
        str.insert(str.length(), "Вы налили себе в стакан  ");
        str.insert(str.length(), content);
        str.insert(str.length(), ".\n");
        return str;
    }

string glass:: use()//употребить
    {
        string str;
        if (content==zero)
            str="Стакан пустой.";
        else 
        {
            str="Вы употребили ";
            str.insert(str.length(),content);
            str.insert(str.length(),".Не забудьте помыть стакан.");
            str=dishes::use(); 
        }
        return str;
    }

    glass::~glass()
    {
    }