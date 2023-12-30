#ifndef LOADING_PAGE_H
#define LOADING_PAGE_H

#include "page.h"

class LoadingPage : protected Page
{
public:
    LoadingPage(sf::RenderWindow *&, State *&, sf::Font *&, float, float);
    ~LoadingPage();
    void update();

private:
    sf::Text text;
    void processEvents();
    void draw();
};

#endif