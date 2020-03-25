/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFML
*/

#include "SFML.hpp"

SFML::SFML()
        : _win(sf::VideoMode(1700, 1000), "ARCADE")
{
    std::cout << "SFML object created !" << std::endl;
}

SFML::~SFML()
{
    _win.close();
    std::cout << "SFML object deleted !" << std::endl;
}

char SFML::check_event()
{
    sf::Event event;

    while (_win.pollEvent(event))
        switch (event.type) {

            case sf::Event::KeyPressed: {
                if (event.key.code == sf::Keyboard::Z)
                    return 'z';
                else if (event.key.code == sf::Keyboard::Q)
                    return 'q';
                else if (event.key.code == sf::Keyboard::S)
                    return 's';
                else if (event.key.code == sf::Keyboard::D)
                    return 'd';
                else if (event.key.code == sf::Keyboard::Enter)
                    return 58;
                else if (event.key.code == sf::Keyboard::G) {
                    delete this;
                    return 'g';
                } else if (event.key.code == sf::Keyboard::Escape) {
                    delete this;
                    return 27;
                }
                break;
            }

            case sf::Event::Closed: {
                delete this;
                return 27;
            }

            default:
                break;
        }
    return '\0';
}

void SFML::display_menu_choices(size_t *cursor)
{
    static int choice = 0;
    static int colors[4] = {6, 5, 5, 5};
    std::string choices[4] = {
        "PACMAN", "NIBBLER", "NCURSES", "SFML"
    };

    *cursor = check_event();
    if (*cursor == 27)
        return;
    if (*cursor == 'q') {
        if (choice == 0)
            return;
        colors[choice] = 5;
        colors[--choice] = 6;
    } else if (*cursor == 'd') {
        if (choice == 3)
            return;
        colors[choice] = 5;
        colors[++choice] = 6;
    }
    display_text(choices[0], 350, 600, 50, colors[0]);
    display_text(choices[1], 685, 600, 50, colors[1]);
    display_text(choices[2], 1050, 600, 50, colors[2]);
    display_text(choices[3], 1400, 600, 50, colors[3]);
    if (*cursor == 58)
        *cursor = choice + 1;
}

std::size_t SFML::display_menu()
{
    size_t cursor;

    while (cursor != 27 && cursor != 1 && cursor != 2 \
        && cursor != 3 && cursor != 4) {
        display_text("ARCADE", 620, 300, 150, 2);
        display_menu_choices(&cursor);
        display_window();
    }
    return cursor;
}

void SFML::display_window()
{
    _win.display();
    _win.clear();
}

sf::Color SFML::check_color(int color)
{
    switch (color)
    {
        case 1:
            return sf::Color::White;
        case 2:
            return sf::Color::Red;
        case 3:
            return sf::Color::Green;
        case 4:
            return sf::Color::Blue;
        case 5:
            return sf::Color::Yellow;
        case 6:
            return sf::Color::Magenta;
        case 7:
            return sf::Color::Cyan;
        default:
            return sf::Color::Black;
    }
}

void SFML::display_text(const std::string &text, float x, float y, float size, int color)
{
    sf::Text box;
    sf::Font font;
    sf::Color c = check_color(color);

    try {
        if (!font.loadFromFile("./ressource/ARCADEPI.TTF"))
            throw("Can't open font.ttf.");
    } catch (const std::string &e) {
        std::cerr << "Exception: " << e << std::endl;
        exit(EXIT_FAILURE);
    }
    box.setFont(font);
    box.setString(text);
    box.setCharacterSize(size);
    box.setFillColor(c);
    box.setPosition(sf::Vector2f(x, y));
    _win.draw(box);
}

void SFML::display_text(const std::string &text, float x, float y)
{
    sf::Text box;
    sf::Font font;

    try {
        if (!font.loadFromFile("./ressource/arial.ttf"))
            throw("Can't open font.ttf.");
    } catch (const std::string &e) {
        std::cerr << "Exception: " << e << std::endl;
        exit(EXIT_FAILURE);
    }
    box.setFont(font);
    box.setString(text);
    box.setCharacterSize(50);
    box.setFillColor(sf::Color::White);
    box.setPosition(sf::Vector2f(x, y));
    _win.draw(box);
}

extern "C"
{
    IGraph *create()
    {
        return new SFML();
    }
}