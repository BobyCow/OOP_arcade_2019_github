/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** NcurseS
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <curses.h>
#include <iostream>
#include "IGraph.hpp"

class Ncurses : public IGraph
{
    public:
        Ncurses();
        virtual ~Ncurses();
        char check_event() final;
        void display_window() final;
        void display_text(const std::string &text, float x, float y) final;
        virtual void display_text(const std::string &text, float x, float y, float size, int color) final;
        virtual std::size_t display_menu() final;
    protected:
    private:
        WINDOW *window;
};

#endif /* !NCURSES_HPP_ */