#ifndef PAGE_H
#define PAGE_H

#include "../UI/state.h"
#include <SFML/Graphics.hpp>

class Page
{
public:
    Page(sf::RenderWindow *&, State *&, sf::Font *&font, float, float);
    virtual void update() = 0;
    virtual ~Page();

protected:
    virtual void draw() = 0;
    virtual void processEvents() = 0;
    sf::RenderWindow *window;
    State *state;
    sf::Font *font;
    float width;
    float height;
};

#endif