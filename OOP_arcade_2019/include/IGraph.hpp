/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGraph
*/

#ifndef IGRAPH_HPP_
#define IGRAPH_HPP_

#include <iostream>

/*
* Interphace for Graphical Libraries
*/
class IGraph
{
    public:
        virtual ~IGraph() = default;
        /*
        * Displays current screen
        */
        virtual void display_window() = 0;
        /*
        * Event Handler (Quit, Resize, movement, ...)
        */
        virtual char check_event() = 0;
        /*
        * Diplays the menu
        */
        virtual std::size_t display_menu() = 0;
        /*
        * Display some text at pos x y
        */
        virtual void display_text(const std::string &text, float x, float y) = 0;
        /*
        * Display some text at pos x y with size and color
        */
        virtual void display_text(const std::string &text, float x, float y, float size, int color) = 0;
    protected:
    private:
};

#endif /* !IGRAPH_HPP_ */
