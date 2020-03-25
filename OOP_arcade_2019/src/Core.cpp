/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** core
*/

#include "Core.hpp"
#include "Error.hpp"
#include "IGraph.hpp"

Core::Core(graphic_lib gl)
        : _gl(gl)
{
    try {
        if (gl == SFML)
            _handler = dlopen("./lib/lib_arcade_sfml.so", RTLD_LAZY);
        else
            _handler = dlopen("./lib/lib_arcade_ncurses.so", RTLD_LAZY);
        if (_handler == NULL)
            throw(dlerror());
    } catch (const char *e) {
        std::cerr << "Exception: " << e << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Core created !" << std::endl;
}

Core::~Core()
{
    std::cout << "Core deleted !" << std::endl;
}

void Core::switch_lib()
{
    try {
        dlclose(_handler);
        if (_gl == SFML) {
            _gl = NCURSES;
            _handler = dlopen("./lib/lib_arcade_ncurses.so", RTLD_LAZY);
            *(void **) (&_GUItemp) = dlsym(_handler, "create");
        } else {
            _gl = SFML;
            _handler = dlopen("./lib/lib_arcade_sfml.so", RTLD_LAZY);
            *(void **) (&_GUItemp) = dlsym(_handler, "create");
        }
        _GUI = _GUItemp();
        if (_handler == NULL)
            throw(dlerror());
    } catch (const char *e) {
        std::cerr << "Exception: " << e << std::endl;
        exit(EXIT_FAILURE);
    }
}

bool Core::check_input(char ev)
{
    switch (ev) {
        case 1: {
            std::cout << "Launch PACMAN !!" << std::endl;
            //lanch_game(PACMAN);
            return false;
        } case 2: {
            std::cout << "Launch NIBBLER !!" << std::endl;
            //lanch_game(NIBBLER);
            return false;
        } case 3: {
            std::cout << "Switch to NCURSES !!" << std::endl;
            // switch_lib();
            return true;
        } case 4: {
            std::cout << "Switch to SFML !!" << std::endl;
            // switch_lib();
            return true;
        } case 'g': {
            switch_lib();
            std::cout << "Switched !!" << std::endl;
            return true;
        } case 'z': {
            std::cout << "Forward !!" << std::endl;
            return true;
        } case 'q': {
            std::cout << "Left !!" << std::endl;
            return true;
        } case 's': {
            std::cout << "Backward !!" << std::endl;
            return true;
        } case 'd': {
            std::cout << "Right !!" << std::endl;
            return true;
        } case 27:
            return false;
        default:
            return true;
    }
    return true;
}

void Core::launch()
{
    char *e;

    try {
        *(void **) (&_GUItemp) = dlsym(_handler, "create");
        _GUI = _GUItemp();
        e = dlerror();
        if (e != NULL)
            throw(e);
    } catch (const char *e) {
        std::cerr << "Exception: " << e << std::endl;
        exit(EXIT_FAILURE);
    }
    while (true)
        if (!check_input(_GUI->display_menu()))
            return;
    while (true) {
        _GUI->display_window();
        if (!check_input(_GUI->check_event()))
            break;
    }
}