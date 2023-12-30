#include "../UI/window.h"
#define font_file "resurce/pixel-anchor-jack_0.ttf"
#include <iostream>

Window::Window()
{
    state = new State();
    window = new sf::RenderWindow;
    window->create(sf::VideoMode::getDesktopMode(), "Dishes",sf::Style::Fullscreen );
    window->setFramerateLimit(60);
    font = new sf::Font;
    if (!(font->loadFromFile(font_file)))
    {
        std::cout << "Error: cannot load font from file" << std::endl;
        exit(EXIT_FAILURE);
    }
    width = static_cast<float>(sf::VideoMode::getDesktopMode().width);
    height = static_cast<float>(sf::VideoMode::getDesktopMode().height);
    loadingPage = new LoadingPage(window, state, font, width, height);
    menuPage = new Main_menu(window,state,font,width,height);                     
}

Window::~Window()
{
    delete loadingPage;
    delete state;
    delete window;
}

void Window::start()
{
    while (window->isOpen())
    {
        switch (state->get_state())
        {
            case State::state::loading_page:
                loadingPage->update();
                break;
            case State::state::main_menu:
                menuPage->start();
                break;
            case State::state::close:
                window->close();
                break;
        }
    }
}