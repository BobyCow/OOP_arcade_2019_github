/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Game
*/

#ifndef GAME_HPP_
#define GAME_HPP_

#include "IGame.hpp"

class Game : public IGame
{
    public:
        Game();
        ~Game();

        void setMap();
        void setPos();
        void setFood();
        void move();
        void display();

    protected:
        //
    private:
        void pause();
};

#endif /* !GAME_HPP_ */
