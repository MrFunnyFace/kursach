#include "../src/dishes.h"

dishes :: dishes():CLEAN(true),V(0),color(zero),content(zero)
{}

dishes :: dishes(double a,bool f,std :: string cont,std :: string col):CLEAN(f),V(a),color(col),content(cont)
{}

string dishes :: clean()
{
    CLEAN=true;
    content=zero;
    return "";
}

string dishes ::fill(string cont ,double v)
{
    string str;
    if (V<v) str="Вы разлили часть!\n";
        content=cont;
        CLEAN=false;
    return str;
}

string dishes :: use()
{
    content=zero;
    return "";
}

ostream& operator <<(ostream& os,dishes& di)
{
    os<<"Объем: "<<di.V<<endl;
    if(di.CLEAN)os<<"Чистая: да"<<endl;
    else os<<"Чистая: нет"<<endl;
    os<<"Цвет: "<<di.color<<endl;
    os<<"Содержимое: "<<di.content<<endl;
    return os;
}

istream& operator>>(istream& in, dishes& d) 
{
	std::cout << "Объем: ";
	do {
    	in >> d.V;
    	if (d.V < 0) std::cout << "Так не бывает. Подумай еще.." << std::endl;
        else  d.CLEAN= false;
    }
    while(d.V<=0);
	cout << "Содержимое (Если хотите оставить пустым, введите 'Nothing'): ";
	in >> d.content;
	std::cout << "Цвет: ";
	in >> d.color;
	return in;
}

dishes::~dishes(){}

void WaitEnter()
{
    char c;
    do
    {
        cout<<"Press Enter to continue"<<endl;
        c=getchar();
    } while (getchar(),c!='\n');
    
}