/*
** EPITECH PROJECT, 2020
** pacman
** File description:
** Pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#include <SFML/Graphics.hpp>
#include <time.h>


//----              SFML             ----//
typedef struct Sfml_s {
    sf::RenderWindow window;
    sf::Texture t1,t2,t3;
    sf::Sprite path;
    sf::Sprite pacman;
    sf::Sprite wall;
    sf::Clock clock;
    sf::Event event;
}Sfml_t;
//----              SFML             ----//

typedef struct Cellule_s {
    int x,y;
    bool wall = true;
}Cellule_t;

class Pacman {
    public:
        Pacman();
        ~Pacman();

        void move();
        void init();
        void setMap();
        bool conditionClose();
        void timing();
        void eventHandler();
        void refresh();
        void display();

    protected:
    private:
        int height, width;
        int tall;
        int height_cell;
        int width_cell;
        int dir,num;
        Cellule_t cell[2400];
        float timer, delay;
        float time;
        char **map;

        //----              SFML             ----//
        Sfml_t stuff;
        //----              SFML             ----//
};


#endif /* !PACMAN_HPP_ */
