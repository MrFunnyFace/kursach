#include "../src/cooker.h"

cooker::cooker():dishes::dishes()
{}

cooker::cooker(double a,bool g,string b,string c):dishes::dishes(a,g,b,c)
{}

string cooker::clean()
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
        str="Вы помыли кострюлю.";
    }
    return str;
}

string cooker:: name()
{
    return "Кастрюля\n";
}

string cooker::info()
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

string cooker :: cook()
    {
        string str;
        if (!CLEAN)
        {   
            str.insert(str.length(),"Сначала помойте кострюлю, это не гигиенично!");
            if(content!=zero)cout<< 
            str.insert(str.length(),"И вылийте все содержимое. Мне кажется или оно двигается?");
        } 
        else 
        {
            str.insert(str.length(),"Что вы будете готовить?");
        }
        return str;
    }
    
    string cooker :: fill(string cont,double v)
    {
        string str;
        if (content!=zero) 
        {
            str.insert(str.length(),"В кострюле уже есть ");
            str.insert(str.length(),content);
            str.insert(str.length()," и благодаря вам он вылетел в трубу.\n");
        }
        else if (!CLEAN) str.insert(str.length(),"Вы приготовили все грязной кастрюле, советую даже не пробовать что у вас вышло(-_-').");
        str.insert(str.length(),dishes::fill(cont,v));
        str.insert(str.length(),"Теперь у вас в кострюле ");
        str.insert(str.length(),content);
        str.insert(str.length(),"\n");
        return str;
    }

    string cooker :: use()//употребить
    {
        string str;
        if (CLEAN) str="В кастрюле пусто.";
        else if (content!=zero) 
        {
            str="В кастрюле ";
            str.insert(str.length(),content);
            str.insert(str.length(),".");
        }
        else 
        {
            dishes::use(); 
            str="Вы использовали все что было в кастрюле.Теперь она грязная";
        }
        return str;
    }

    cooker::~cooker(){}