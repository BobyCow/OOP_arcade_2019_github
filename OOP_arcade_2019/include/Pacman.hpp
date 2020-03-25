/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include "IGame.hpp"

class Pacman : public IGame
{
    public:
        Pacman();
        ~Pacman();

        void setMap();
        void setPos();
        void setFood();
        void move();
        void display();

    protected:
        //
    private:
        //
};

#endif /* !PACMAN_HPP_ */
