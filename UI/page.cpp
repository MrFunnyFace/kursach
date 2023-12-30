#include "../UI/page.h"

Page::Page(sf::RenderWindow *&w, State *&s, sf::Font *&f, float wid, float h)
    : state(s), font(f), width(wid), height(h) 
{
    window = w;
}

Page::~Page() {}