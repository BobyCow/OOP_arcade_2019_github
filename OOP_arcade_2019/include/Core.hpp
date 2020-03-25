/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** core
*/

//use dlopen (lib_name; RTLD_Lazy); dlclose;dlsym

#ifndef CORE_HPP_
#define CORE_HPP_

#include "ICore.hpp"
#include "IGame.hpp"
#include <iostream>
#include <dlfcn.h>
#include "Ncurses.hpp"

enum graphic_lib {
    SFML    = 0,
    NCURSES = 1
};

enum state_game {
    NIBBLER = 0,
    PACMAN  = 1
};

class Core : public ICore
{
    public:
        Core(graphic_lib gl);
        virtual ~Core();
        void launch();
        bool check_input(char ev);
        void handle_game(IGraph *);
        void switch_lib();

    private:
        void *_handler;
        graphic_lib _gl;
        IGraph *(*_GUItemp)(void);
        IGraph *_GUI;
        state_game current_game;
    protected:
};

#endif /* !CORE_HPP_ */
