#include "../UI/main_menu.h"
#include <sstream>

Main_menu::Main_menu(sf::RenderWindow *&w, State *&s, sf::Font *&f, float width, float height) : Page(w, s, f, width, height), activeButton(Buttons::first)
{
    text.setFont(*font);
    text.setFillColor(sf::Color::White);
    rectangle.setSize(sf::Vector2f(300, 60));
    size=4;
    Plist=0;
    list = new (std::nothrow) dishes*[size];
        if(list==nullptr)cout<<"Проблемы в конструкторе!"<<endl;
    Point_obj=999;
    flag=1;
}

bool Main_menu::isEmpty()
{
    if(Plist==0) return true;
    else return false;
}

bool Main_menu::isFull()
{
    if(Plist==size)return true;
    else return false;
}

Main_menu::~Main_menu() {}

void Main_menu::start()
{
    processWindow();
    draw();
}

void Main_menu::update()
{
 
    processEvents();
    switch(state->get_state())
    {
        case State::state::main_menu : draw();break;   
        case State::state::show_list : draw_list();break;
        case State::state::add_obj : draw_add();break;
        case State::state::get_result : get_result();break;
        case State::state::standard_methods : 
            {
                if(Point_obj==999)menu_obj();
                else draw_met_obj();
            }
            break;

        case State::state::unique_methods :  if(Point_obj==999)menu_obj(); break;
    }
}

void Main_menu::processWindow()
{
      while (window->isOpen())
    {
        switch (state->get_state())
        {
            case State::state::main_menu:
                update();
                break;
            case State::state::show_list :
                update();
                break;
            case State::state::add_obj:
                update();
                break;
            case State::state::standard_methods:
                update();
                break;
            case State::state::unique_methods:
                update();
                break;
            case State::state::get_result:
                update();
                break;
            case State::state::close:
                window->close();
                break;
        }
    }
}


void Main_menu::processEvents()
{
    
    sf::Event event;
    while(window->pollEvent(event))
        {
        switch(state->get_state())
        {
            case State::state::main_menu :
            {  
                    switch (event.type)
                        {
                        case sf::Event::Closed:
                            state->set_state(State::state::close);
                            break;
                        case sf::Event::KeyReleased:
                            switch (event.key.code)
                            {
                            case sf::Keyboard::Enter:
                                switch (activeButton)
                                {
                                case Main_menu::Buttons::first :
                                    state->set_state(State::state::show_list);
                                    break;
                                case Main_menu::Buttons::second:
                                    {
                                        state->set_state(State::state::add_obj);
                                        activeButton=Buttons::first;
                                    }
                                    break;
                                case Main_menu::Buttons::third:
                                    {
                                        state->set_state(State::state::standard_methods);
                                        activeButton=Buttons::first;
                                    }
                                    break;
                                case Main_menu::Buttons::four :
                                    {
                                        state->set_state(State::state::unique_methods);
                                        activeButton=Buttons::first;
                                    }
                                    break;
                                case Main_menu::Buttons::exit:
                                    state->set_state(State::state::close);
                                    break;
                                default:
                                    break;
                                }
                                break;
                            case sf::Keyboard::Up:
                                moveUp(5);
                                break;
                            case sf::Keyboard::Down:
                                moveDown(5);
                                break;
                            }    
                }
            }
            break;


            case State::state::show_list :
            {
                        switch (event.type)
                            {
                                case sf::Event::Closed:
                                    {
                                        state->set_state(State::state::close);
                                        update();
                                    }
                                    break;
                                case sf::Event::KeyReleased:
                                    {
                                        activeButton=Buttons::first;
                                        state->set_state(State::state::main_menu);
                                        update();
                                    }
                                    break;                        
                                
                                default:
                                break;
                            }
        
            }
            break;

            case State::state::add_obj :
            {
                switch (isFull())
                {
                case true:
                     switch (event.type)
                            {
                                case sf::Event::Closed:
                                    {
                                        state->set_state(State::state::close);
                                        update();
                                    }
                                    break;
                                case sf::Event::KeyReleased:
                                    {
                                        state->set_state(State::state::main_menu);
                                        activeButton=Buttons::first;
                                        update();
                                    }
                                    break;                        
                                
                                default:
                                break;
                            }
                    break;

                case false:
                    {
                    switch (event.type)
                        {
                        case sf::Event::Closed:
                            state->set_state(State::state::close);
                            break;
                        case sf::Event::KeyReleased:
                            switch (event.key.code)
                            {
                            case sf::Keyboard::Enter:
                                switch (activeButton)
                                {
                                case Main_menu::Buttons::first :
                                    {
                                        string col=box("Какой цвет будет у кружки:");
                                        double v=Dbox("Введите объем кружки:");    
                                        list[Plist]=new (std::nothrow) pot{v,true,zero,col};
                                        Plist+=1;
                                        activeButton=Buttons::first;
                                        state->set_state(State::state::main_menu);
                                    }
                                    break;
                                case Main_menu::Buttons::second:
                                    {
                                        string col=box("Какой цвет будет у кастрюли:");
                                        double v=Dbox("Введите объем кастрюли:");
                                        list[Plist]=new (std::nothrow) cooker{v,true,zero,col};
                                        Plist+=1;                 
                                        activeButton=Buttons::first;                      
                                        state->set_state(State::state::main_menu);
                                    }
                                    break;
                                case Main_menu::Buttons::third:
                                    {
                                        string col=box("Какой цвет будет у тарелки:");
                                        double v=Dbox("Введите объем тарелки:");
                                        list[Plist]=new (std::nothrow) plate{v,true,zero,col};
                                        Plist+=1;
                                        activeButton=Buttons::first;
                                        state->set_state(State::state::main_menu);
                                    }
                                    break;
                                case Main_menu::Buttons::four :
                                    {
                                        string col=box("Какой цвет будет у стакана:");
                                        double v=Dbox("Введите объем стакана:");
                                        list[Plist]=new (std::nothrow) glass{v,true,zero,col};
                                        Plist+=1;
                                        activeButton=Buttons::first;
                                        state->set_state(State::state::main_menu);
                                    }
                                    break;
                                case Main_menu::Buttons::exit:
                                    {
                                        activeButton=Buttons::first;
                                        state->set_state(State::state::main_menu);
                                    }
                                    break;
                                default:
                                    break;
                                }
                                break;
                            case sf::Keyboard::Up:
                                moveUp(5);
                                break;
                            case sf::Keyboard::Down:
                                moveDown(5);
                                break;
                            }    
                        }
                    }
                    break;    
                
                default:
                    break;
                }
            }
            break;



            case State::state::standard_methods:
            {
                switch (isEmpty())
                {
                case true:
                     switch (event.type)
                            {
                                case sf::Event::Closed:
                                    {
                                        state->set_state(State::state::close);
                                        update();
                                    }
                                    break;
                                case sf::Event::KeyReleased:
                                    {
                                        state->set_state(State::state::main_menu);
                                        update();
                                    }
                                    break;                        
                                
                                default:
                                break;
                            }
                    break;

                case false:
                        {
                            switch(Point_obj)
                                    {
                                        case 999:
                                        {
                                            switch (event.type)
                                            {
                                                case sf::Event::Closed:
                                                    {
                                                        state->set_state(State::state::close);
                                                    }
                                                break;
                                                case sf::Event::KeyReleased:
                                                    switch (event.key.code)
                                                {
                                                    case sf::Keyboard::Enter:
                                                        switch (activeButton)
                                                        {
                                                        case Main_menu::Buttons::first :
                                                            {
                                                                Point_obj=0;
                                                                activeButton=Buttons::first;
                                                            }
                                                            break;
                                                        case Main_menu::Buttons::second:
                                                            {
                                                                Point_obj=1;
                                                                activeButton=Buttons::first;
                                                            }
                                                            break;
                                                        case Main_menu::Buttons::third:
                                                                {
                                                                    Point_obj=2;
                                                                    activeButton=Buttons::first;
                                                                }
                                                            break;
                                                        case Main_menu::Buttons::four :
                                                            {
                                                                Point_obj=3;
                                                                activeButton=Buttons::first;
                                                            }
                                                            break;
                                                        case Main_menu::Buttons::exit:
                                                            state->set_state(State::state::main_menu);
                                                            break;
                                                        default:
                                                            break;
                                                        }
                                                        break;
                                                    case sf::Keyboard::Up:
                                                        moveUp(Plist+1);
                                                        break;
                                                    case sf::Keyboard::Down:
                                                        moveDown(Plist+1);
                                                        break;
                                                    default:break;
                                                }    
                                            }
                                }
                                break;


                                default:
                                {
                                 switch (event.type)
                                            {
                                                case sf::Event::Closed:
                                                    {
                                                        state->set_state(State::state::close);
                                                    }
                                                break;
                                                case sf::Event::KeyReleased:
                                                    switch (event.key.code)
                                                {
                                                    case sf::Keyboard::Enter:
                                                        switch (activeButton)
                                                        {
                                                        case Main_menu::Buttons::first :
                                                            {
                                                                cont=box("Что налить:");
                                                                viob=Dbox("Сколько налить:");
                                                                result=list[Point_obj]->fill(cont,viob);
                                                                state->set_state(State::state::get_result);
                                                            }
                                                            break;
                                                        case Main_menu::Buttons::second:
                                                            {
                                                                result=list[Point_obj]->clean();
                                                                state->set_state(State::state::get_result);
                                                            }
                                                            break;
                                                        case Main_menu::Buttons::third:
                                                            {
                                                                result=list[Point_obj]->use();
                                                                state->set_state(State::state::get_result);
                                                            }
                                                            break;
                                                        case Main_menu::Buttons::exit:
                                                            state->set_state(State::state::main_menu);
                                                            break;
                                                        default:
                                                            break;
                                                        }
                                                        break;
                                                    case sf::Keyboard::Up:
                                                        moveUp(4);
                                                        break;
                                                    case sf::Keyboard::Down:
                                                        moveDown(4);
                                                        break;
                                                    default:break;
                                                }    
                                            }
                                }
                                break;



                            }

                        
                        }   
                }
            }
            break;


            case State::state::unique_methods:
            {
                switch (isEmpty())
                {
                case true:
                     switch (event.type)
                            {
                                case sf::Event::Closed:
                                    {
                                        state->set_state(State::state::close);
                                        update();
                                    }
                                    break;
                                case sf::Event::KeyReleased:
                                    {
                                        if(sf::Keyboard::Enter)
                                        {
                                            state->set_state(State::state::main_menu);
                                            update();
                                        }
                                    }
                                    break;                        
                            
                                default:
                                break;
                            }
                    break;

                case false:
                        {
                            switch(Point_obj)
                                    {
                                        case 999:
                                        {
                                            switch (event.type)
                                            {
                                                case sf::Event::Closed:
                                                    {
                                                        state->set_state(State::state::close);
                                                    }
                                                break;
                                                case sf::Event::KeyReleased:
                                                    switch (event.key.code)
                                                {
                                                    case sf::Keyboard::Enter:
                                                        switch (activeButton)
                                                        {
                                                        case Main_menu::Buttons::first :
                                                            {
                                                                Point_obj=0;
                                                                activeButton=Buttons::first;
                                                            }
                                                            break;
                                                        case Main_menu::Buttons::second:
                                                            {
                                                                Point_obj=1;
                                                                activeButton=Buttons::first;
                                                            }
                                                            break;
                                                        case Main_menu::Buttons::third:
                                                                {
                                                                    Point_obj=2;
                                                                    activeButton=Buttons::first;
                                                                }
                                                            break;
                                                        case Main_menu::Buttons::four :
                                                            {
                                                                Point_obj=3;
                                                                activeButton=Buttons::first;
                                                            }
                                                            break;
                                                        case Main_menu::Buttons::exit:
                                                            state->set_state(State::state::main_menu);
                                                            break;
                                                        default:
                                                            break;
                                                        }
                                                        break;
                                                    case sf::Keyboard::Up:
                                                        moveUp(Plist+1);
                                                        break;
                                                    case sf::Keyboard::Down:
                                                        moveDown(Plist+1);
                                                        break;
                                                    default:break;
                                                }    
                                            }
                                }
                                break;


                                default:
                                {
                                    if (event.type)
                                    {
                                       
                                        if (typeid(*list[Point_obj])==typeid(pot))
                                            {
                                                pot*a=(pot*)list[Point_obj];
                                                result=a->DrinkTea();
                                            }
                                        else if (typeid(*list[Point_obj])==typeid(glass))
                                            {
                                                glass *a=(glass*)list[Point_obj];
                                                list[Point_obj]=a;
                                                result=a->broke();
                                                delete a;
                                                int b=Point_obj+1;
                                                while (list[b]!=nullptr)         
                                                {
                                                    list[b-1]=list[b];
                                                    list[b]=nullptr;
                                                    b++;
                                                }
                                                Plist-=1; 
                                            }
                                        else if (typeid(*list[Point_obj])==typeid(plate))
                                            {
                                                plate* a=(plate*)list[Point_obj];
                                                result=a->fly_plate();
                                            }
                                        else if (typeid(*list[Point_obj])==typeid(cooker))
                                            {
                                                cooker* a=(cooker*)list[Point_obj];
                                                result=a->cook();
                                            }    
                                        state->set_state(State::state::get_result);
                                    
                                    }
                                }



                            }

                        
                        }   
                }
            }
            break;

            case State::state::get_result :
            {
                if (event.type == sf::Event::Closed)
                    {
                                state->set_state(State::state::close);
                                update();
                    }

                if (event.key.code ==sf::Keyboard::Enter )
                {
                    result="";
                    Point_obj=999;
                    activeButton=Buttons::first;
                    state->set_state(State::state::main_menu);
                    update();
                }
              
        
            }
            break;

            default: 
            break;
        }
    }
}





void Main_menu::draw()
{
    window->clear(sf::Color::Green);
    std::string str = "Курсовая работа";
    sf::Text txt;
    txt.setFont(*font);
    txt.setString(sf::String::fromUtf8(str.begin(),str.end()));
    txt.setCharacterSize(95);
    txt.setOrigin(sf::Vector2f(txt.getGlobalBounds().width/2,txt.getGlobalBounds().height/2));
    txt.setPosition(sf::Vector2f(width/2,height/2-250));
    text.setCharacterSize(30);
    window->draw(txt);
    drawButton("ВЫВЕСТИ СОДЕРЖИМОЕ ШКАФА", width / 2, height * 0.5-50, activeButton == Buttons::first ? sf::Color::White : sf::Color::Black);
    drawButton("ДОБАВИТЬ ПОСУДУ", width / 2, height * 0.5 + 50, activeButton == Buttons::second ? sf::Color::White : sf::Color::Black);
    drawButton("СТАНДАРТНЫЕ МЕТОДЫ", width / 2, height * 0.5 + 150, activeButton == Buttons::third ? sf::Color::White : sf::Color::Black);
    drawButton("УНИКАЛЬНЫЕ МЕТОДЫ", width / 2, height * 0.5 + 250, activeButton == Buttons::four ? sf::Color::White : sf::Color::Black);
    drawButton("ВЫХОД", width / 2, height * 0.5 + 350, activeButton == Buttons::exit ? sf::Color::White : sf::Color::Black);
    window->display();
}

void Main_menu::draw_list()
{
        switch (isEmpty())
            {
                case true :
                    {
                        window->clear(sf::Color::Red);
                        std::string str = "ТУТ НИЧЕГО НЕТ";
                        sf::Text txt;
                        txt.setFont(*font);
                        txt.setString(sf::String::fromUtf8(str.begin(),str.end()));
                        txt.setCharacterSize(95);
                        txt.setOrigin(sf::Vector2f(txt.getGlobalBounds().width/2,txt.getGlobalBounds().height/2));
                        txt.setPosition(sf::Vector2f(width/2,height/2-250));
                        window->draw(txt);
                        window->display();
                    }
                break;

                case false :
                    {      
                        window->clear(sf::Color::Blue);
                        sf::Text pa=TxT("Посуда",95,font);
                        pa.setPosition(sf::Vector2f(width/2,+pa.getGlobalBounds().height));
                        window->draw(pa);
                        for(int i=0;i<Plist;i++)
                            {
                                string str[Plist];
                                str[i]=list[i]->info();
                                sf::Text txt=TxT(str[i],35,font);
                                int wh, hg;
                                switch(i)
                                {
                                    case 0:{wh=0;hg=0;}break;
                                    case 1:{wh=900;hg=0;}break;
                                    case 2:{wh=0;hg=600;}break;
                                    case 3:{wh=900;hg=600;}break;
                                }
                                txt.setPosition(sf::Vector2f(txt.getGlobalBounds().width+wh,txt.getGlobalBounds().height+300+hg));
                                window->draw(txt);
                                
                            }
                        window->display();
                    }
                    break;

                default: 
                    break;
            }

}


void Main_menu::draw_add()
{
    switch(isFull())
        {
            case true:
            {
                window->clear(sf::Color::Red);
                std::string str = "ПЕРЕПОЛНЕНО";
                sf::Text txt;
                txt.setFont(*font);
                txt.setString(sf::String::fromUtf8(str.begin(),str.end()));
                txt.setCharacterSize(95);
                txt.setOrigin(sf::Vector2f(txt.getGlobalBounds().width/2,txt.getGlobalBounds().height/2));
                txt.setPosition(sf::Vector2f(width/2,height/2-250));
                window->draw(txt);
                window->display();
            }
            break;

            case false:
            {
                    window->clear(sf::Color::Green);
                    std::string str = "ДОБАВИТЬ ПОСУДУ";
                    sf::Text txt;
                    txt.setFont(*font);
                    txt.setString(sf::String::fromUtf8(str.begin(),str.end()));
                    txt.setCharacterSize(95);
                    txt.setOrigin(sf::Vector2f(txt.getGlobalBounds().width/2,txt.getGlobalBounds().height/2));
                    txt.setPosition(sf::Vector2f(width/2,height/2-250));
                    text.setCharacterSize(30);
                    window->draw(txt);
                    drawButton("ДОБАВИТЬ ЧАШКУ", width / 2, height * 0.5-50, activeButton == Buttons::first ? sf::Color::White : sf::Color::Black);
                    drawButton("ДОБАВИТЬ КАСТРЮЛЮ", width / 2, height * 0.5 + 50, activeButton == Buttons::second ? sf::Color::White : sf::Color::Black);
                    drawButton("ДОБАВИТЬ ТАРЕЛКУ", width / 2, height * 0.5 + 150, activeButton == Buttons::third ? sf::Color::White : sf::Color::Black);
                    drawButton("ДОБАВИТЬ СТАКАН", width / 2, height * 0.5 + 250, activeButton == Buttons::four ? sf::Color::White : sf::Color::Black);
                    drawButton("НАЗАД", width / 2, height * 0.5 + 350, activeButton == Buttons::exit ? sf::Color::White : sf::Color::Black);
                    window->display();
            }

            default:break;
        }
}

void Main_menu::drawButton(std::string str, float x, float y, sf::Color color)
{
    text.setString(sf::String::fromUtf8(str.begin(), str.end()));
    text.setPosition(x - text.getLocalBounds().width / 2, y - rectangle.getLocalBounds().height * 0.4);
    rectangle.setSize(sf::Vector2f(750 , 50));
    rectangle.setPosition(x - rectangle.getLocalBounds().width / 2, y - rectangle.getLocalBounds().height / 2);
    rectangle.setFillColor(color);
    window->draw(rectangle);
    if (color == sf::Color::Black)
    {
        text.setFillColor(sf::Color::White);
    }
    else
    {
        text.setFillColor(sf::Color::Black);
    }
    window->draw(text);
}

void Main_menu::moveUp(int i)
{
    int b = (int)activeButton;
    if (--b < 0)
    {
        b = i - 1;
    }
    activeButton = (Buttons)b;
}

void Main_menu::moveDown(int i)
{
    int b = (int)activeButton;
    if (++b >= i)
    {
        b = 0;
    }
    activeButton = (Buttons)b;
}

sf::Text Main_menu::TxT(string str,int size,sf::Font *font)
{
    sf::Text txt;
    txt.setFont(*font);
    txt.setString(sf::String::fromUtf8(str.begin(),str.end()));
    txt.setCharacterSize(size);
    txt.setOrigin(sf::Vector2f(txt.getGlobalBounds().width/2,txt.getGlobalBounds().height/2));
    return txt;
}

string Main_menu::box (string p)
{
    sf::String text;
    sf::Text txt21;
    txt21.setFont(*font);
    txt21.setString(text.fromUtf8(p.begin(),p.end()));
    txt21.setColor(sf::Color::Black);
    txt21.setPosition(sf::Vector2f (0,0)); 
    sf::RenderWindow windowB(sf::VideoMode(800, 250), "Realization enter date string");
    std::string str;
    sf::Text txt;
    txt.setColor(sf::Color::Black);
    txt.setFont(*font);
    txt.setCharacterSize(25);
    txt.setPosition(0,100);
    int lengthInput = 15;
    bool textChanged=false;
    while (windowB.isOpen())
    {

        sf::Event event;
            while (windowB.pollEvent(event))
                {
                    if (sf::Event::KeyReleased && event.key.code == sf::Keyboard::BackSpace)
                    {
                            if (str.size() > 0)str.pop_back();
                    }
                    else if (sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left)
                    {
                        return str;
                    }   
                    else if (event.type == sf::Event::TextEntered && str.size() <= lengthInput && event.text.unicode < 128 && !textChanged)
                    {
                        str += event.text.unicode;
                        textChanged = true;
                    }
                    else if (event.type == sf::Event::TextEntered && str.size() <= lengthInput && event.text.unicode < 128 && event.text.unicode != str[str.size()-1])
                    {
                        str += event.text.unicode;
                        textChanged = true;
                    }
                    if (event.type == sf::Event::KeyReleased)
                    {
                        textChanged = false;
                    }
                    txt.setString( text.fromUtf8(str.begin(),str.end()));
                }
                if (event.type == sf::Event::Closed)
                    windowB.close();
    windowB.clear(sf::Color::White);
    windowB.draw(txt21);
    windowB.draw(txt);
    windowB.display();
}   
    return str;
}

double Main_menu::Dbox (string p)
{
    sf::String text;
    sf::Text txt21;
    txt21.setFont(*font);
    txt21.setString(text.fromUtf8(p.begin(),p.end()));
    txt21.setColor(sf::Color::Black);
    txt21.setPosition(sf::Vector2f (0,0)); 
    sf::RenderWindow windowB(sf::VideoMode(800, 250), "Realization enter date double");
    std::string str;
    sf::Text txt;
    txt.setColor(sf::Color::Black);
    txt.setFont(*font);
    txt.setCharacterSize(25);
    txt.setPosition(sf::Vector2f (0,100));
    int lengthInput = 15;
    bool textChanged=false;
    double d;
    std::stringstream ss;
    while (windowB.isOpen())
    {

        sf::Event event;
            while (windowB.pollEvent(event))
                {
                    if (sf::Event::KeyReleased && event.key.code == sf::Keyboard::BackSpace)
                    {
                            if (str.size() > 0)str.pop_back();
                    }
                    else if (sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right)
                    {
                            ss<<str;
                            ss>>d;
                            return d;
                    }   
                    else if (event.type == sf::Event::TextEntered && str.size() <= lengthInput && event.text.unicode < 128 && !textChanged)
                    {
                        str += event.text.unicode;
                        textChanged = true;
                    }
                    else if (event.type == sf::Event::TextEntered && str.size() <= lengthInput && event.text.unicode < 128 && event.text.unicode != str[str.size()-1])
                    {
                        str += event.text.unicode;
                        textChanged = true;
                    }
                    if (event.type == sf::Event::KeyReleased)
                    {
                        textChanged = false;
                    }
                    txt.setString( text.fromUtf8(str.begin(),str.end()));
                }
                if (event.type == sf::Event::Closed)
                    windowB.close();

    windowB.clear(sf::Color::White);
    windowB.draw(txt21);
    windowB.draw(txt);
    windowB.display();
}  
    ss<<str;            
    ss>>d;
    return d;
}


void Main_menu::draw_met_obj()
{
    window->clear(sf::Color::Green);
    std::string str = "ВЫБЕРИТЕ МЕТОД";
    sf::Text txt;
    txt.setFont(*font);
    txt.setString(sf::String::fromUtf8(str.begin(),str.end()));
    txt.setCharacterSize(95);
    txt.setOrigin(sf::Vector2f(txt.getGlobalBounds().width/2,txt.getGlobalBounds().height/2));
    txt.setPosition(sf::Vector2f(width/2,height/2-250));
    text.setCharacterSize(30);
    window->draw(txt);
    drawButton("НАЛИТЬ", width / 2, height * 0.5-50, activeButton == Buttons::first ? sf::Color::White : sf::Color::Black);
    drawButton("ПОМЫТЬ", width / 2, height * 0.5 + 50, activeButton == Buttons::second ? sf::Color::White : sf::Color::Black);
    drawButton("ИСПОЛЬЗОВАТЬ", width / 2, height * 0.5 + 150, activeButton == Buttons::third ? sf::Color::White : sf::Color::Black);
    drawButton("НАЗАД", width / 2, height * 0.5 + 250, activeButton == Buttons::exit ? sf::Color::White : sf::Color::Black);
    window->display();
}    


void Main_menu::menu_obj()
{
        switch (isEmpty())
        {
       case true :
            {
                window->clear(sf::Color::Red);
                std::string str = "ТУТ НИЧЕГО НЕТ";
                sf::Text txt;
                txt.setFont(*font);
                txt.setString(sf::String::fromUtf8(str.begin(),str.end()));
                txt.setCharacterSize(95);
                txt.setOrigin(sf::Vector2f(txt.getGlobalBounds().width/2,txt.getGlobalBounds().height/2));
                txt.setPosition(sf::Vector2f(width/2,height/2-250));
                window->draw(txt);
                window->display();
            }
            break;
        
        case false:
            {   
                window->clear(sf::Color::Blue);
                sf::Text txt;
                std::string str = "ВЫБЕРИТЕ ОБЪЕКТ";
                txt.setFont(*font);
                txt.setString(sf::String::fromUtf8(str.begin(),str.end()));
                txt.setCharacterSize(95);
                txt.setOrigin(sf::Vector2f(txt.getGlobalBounds().width/2,txt.getGlobalBounds().height/2));
                txt.setPosition(sf::Vector2f(width/2,height/2-250));
                for(int i=0;i<Plist;i++)
                {
                    int d=i+1;
                        drawButton(list[i]->name(), width / 2, height * 0.5-50+i*100, activeButton == (Buttons)d ? sf::Color::White : sf::Color::Black);
                }
                drawButton("НАЗАД", width / 2, height * 0.5 + 350, activeButton == Buttons::exit ? sf::Color::White : sf::Color::Black);
                window->draw(txt);
                window->display();
            }
            break;

        default:
            break;
        }

}


void Main_menu:: get_result()
    {
            window->clear(sf::Color::Blue);    
            sf::Text txt;
            txt.setFont(*font);
            txt.setCharacterSize(25);
            text.setColor(sf::Color::Black);
            txt.setPosition(sf::Vector2f(width/2,height/2));
            txt.setString(sf::String::fromUtf8(result.begin(),result.end()));
            txt.setOrigin(sf::Vector2f(txt.getGlobalBounds().width/2 , txt.getGlobalBounds().height/2));
            window->draw(txt);
            window->display();
    }  
    



void Main_menu::draw_uni_obj()
{
            window->clear(sf::Color::Blue);    
            std::string str="уникальный метод";
            sf::Text txt;
            txt.setFont(*font);
            txt.setCharacterSize(45);
            text.setColor(sf::Color::Black);
            txt.setString(sf::String::fromUtf8(str.begin(),str.end()));
            txt.setOrigin(sf::Vector2f(txt.getGlobalBounds().width/2,txt.getGlobalBounds().height/2));
            txt.setPosition(sf::Vector2f(width/2,height/2));
            window->draw(txt);
            window->display();
}