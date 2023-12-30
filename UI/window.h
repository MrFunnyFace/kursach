#ifndef WINDOW_H
#define WINDOW_H

#include "../UI/state.h"
#include "SFML/Graphics.hpp"
#include "../UI/loading_page.h"
#include "../UI/main_menu.h"
#include "../src/dishes.h"


class Window: public State
{
    public:
    Window();
    void start();
    ~Window();

private:
    float width;
    float height;
    LoadingPage *loadingPage;
    Main_menu *menuPage;    
    sf::RenderWindow *window;
    State *state;
    sf::Font *font;
};
#endif