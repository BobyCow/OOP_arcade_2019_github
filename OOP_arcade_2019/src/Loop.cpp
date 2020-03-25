/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Loop
*/

#include "Core.hpp"

int start_arcade(const std::string &filename)
{
    graphic_lib gl;

    if (filename.find("lib_arcade_sfml.so") != std::string::npos)
        gl = SFML;
    else if (filename.find("lib_arcade_ncurses.so") != std::string::npos)
        gl = NCURSES;
    else {
        std::cerr << "Unrecognized graphical library." << std::endl;
        return 84;
    }
    Core core(gl);
    core.launch();
    return 0;
}