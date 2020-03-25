/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include "IGame.hpp"
#include "IGraph.hpp"

class Nibbler : public IGame
{
    public:
        Nibbler(IGraph *graph);
        ~Nibbler();

        void setMap();
        void setPos();
        void setFood();
        void move();
        void display();

    protected:
        //
    private:
        void setEnemies();
        void setGhost();
        IGraph *_graph;
};

#endif /* !NIBBLER_HPP_ */
