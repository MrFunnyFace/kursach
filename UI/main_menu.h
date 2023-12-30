#ifndef MENU_PAGE_H
#define MENU_PAGE_H

#include "../UI/page.h"
#include "../src/plate.h"
#include "../src/dishes.h"
#include "../src/pot.h"
#include "../src/glass.h"
#include "../src/cooker.h"


#include <iostream>
#include <ctime>
#include <string>
#include <string>
#include <sstream>

class Main_menu : protected Page 
{
public:
    Main_menu(sf::RenderWindow *&,State *&, sf::Font *&, float, float);
    ~Main_menu();

    void start();

    void update();

    sf::Text TxT(string str,int size,sf::Font *font);
    string box(string);
    double Dbox(string);
    

private:
    int flag;
    int viob;
    string cont;
    int Point_obj;
    dishes** list;
    int Plist;
    int size;
    bool isEmpty();
    bool isFull();
    enum class Buttons
    {exit,first,second,third,four};
    Buttons activeButton;
    
    void draw_uni_obj();
/*    void fill_obj();
    void clean_obj();
    void use_obj(); */


    void drawButton(std::string, float, float, sf::Color);
    sf::Text text;
    sf::RectangleShape rectangle;

    void processWindow();
    void processEvents();
    
    string result;
    void draw();
    void draw_list();
    void get_result();
    void draw_met_obj();
    void draw_add();
    void menu_obj();

    void moveUp(int);
    void moveDown(int);
    
};
#endif

/* void menu::met_obj() {
	if (isEmpty()) {
    	cout << "Здесь пусто" << endl;
    	WaitEnter();
    	return;
	}
    int choise,num;
    bool c;
    do
    {
        system("clear");
        
        else c=false;

    } while (c);
    
    do {
    system("clear");
	cout << "Какой из методов вы хотите выполнить?" << endl;
	cout << "1. Налить указанный объем жидкости." << endl;
	cout << "2. Помыть." << endl;
	cout << "3. Выпить содержимое." << endl;
	cout << "0. Выход." << endl;
    cin >> choise;
    double v;
	string content;
	switch (choise)
	{
        case 0:
            return;
        case 1:
        {
           cout << "Объем: ";
            do {
                cin >> v;
                if (v < 0)cout << "Это хорошо ты придумал. А если подумать?" << endl;
            } while (v < 0);
            cout << "Содержимое: ";
            cin >> content;
                list[num-1]->name();
                list[num-1]->fill(content,v);
            
            break;
        }
        case 2:
        {
                list[num-1]->name();
                list[num-1]->clean();
            break;
        }
        case 3:
        {
                list[num-1]->name();
                list[num-1]->use();
                cout << endl;
            
            break;
        }
        default:
            break;
        }
	WaitEnter();
    } 
    while(choise);
} */