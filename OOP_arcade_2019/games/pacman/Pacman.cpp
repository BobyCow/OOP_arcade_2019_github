/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Pacman
*/

#include "Pacman.hpp"
#include "Tool.hpp"


Pacman::Pacman()
{
    height = 60;
    width = 40;
    tall = 16;
    height_cell = tall * height;
    width_cell = tall * width;
    dir = 4;
    num = 4;
    timer = 0;
    delay = 0.05;
}

Pacman::~Pacman()
{
}

void Pacman::refresh()
{
    //----              SFML             ----//
    this->stuff.window.clear();
    //----              SFML             ----//
}

void Pacman::eventHandler()
{
    //----              SFML             ----//
    while (this->stuff.window.pollEvent(this->stuff.event)) {
        if (this->stuff.event.type == sf::Event::Closed)
            this->stuff.window.close();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            this->dir = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            this->dir = 2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
            this->dir = 3;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
            this->dir = 0;
    //----              SFML             ----//
}

void Pacman::timing()
{
    //----              SFML             ----//
    this->time = this->stuff.clock.getElapsedTime().asSeconds();
    this->stuff.clock.restart();
    this->timer += this->time;
    //----              SFML             ----//

}

bool Pacman::conditionClose()
{
    //----              SFML             ----//
    return (this->stuff.window.isOpen());
    //----              SFML             ----//
}

void Pacman::init()
{
    //----              SFML             ----//
    this->stuff.window.create(sf::VideoMode(1920, 1080), "Pacman");
    this->stuff.t1.loadFromFile("images/white.png");
    this->stuff.t2.loadFromFile("images/red.png");
    this->stuff.t3.loadFromFile("images/green.png");
    this->stuff.path.setTexture(this->stuff.t1);
    this->stuff.pacman.setTexture(this->stuff.t2);
    this->stuff.wall.setTexture(this->stuff.t3);
    //----              SFML             ----//
}

void Pacman::setMap()
{
    Tool tool;
    this->map = tool.strlist(tool.openmafile("data.txt"));

}

void Pacman::move()
{
    if (this->timer > this->delay) {
        this->timer = 0;
        if (this->dir == 0) this->cell[0].y+=1;      
        if (this->dir == 1) this->cell[0].x-=1;        
        if (this->dir == 2) this->cell[0].x+=1;         
        if (this->dir == 3) this->cell[0].y-=1;   
        if (this->dir == 4) {
            cell[0].x += 0;
            cell[0].y += 0;
        }
        if (this->cell[0].x > this->height) this->cell[0].x = 0;  
        if (this->cell[0].x < 0) this->cell[0].x = height;
        if (this->cell[0].y > this->width) this->cell[0].y = 0;  
        if (this->cell[0].y < 0) this->cell[0].y = width;
 
        for (int i = 1;i < this->num; i++)
            if (this->cell[0].x == this->cell[i].x && this->cell[0].y == this->cell[i].y)
                this->num = i;
    }

}

void Pacman::display()
{
    for (int i = 0; i <= this->height; i++) 
      for (int j = 0; j <= this->width; j++) { 
          //----              SFML             ----//
          this->stuff.path.setPosition(i*this->tall, j*this->tall);
          this->stuff.window.draw(this->stuff.path);
          //----              SFML             ----// 
      }
    for (int i = 0; i <=this->height; i++) 
      for (int j = 0; j <= this->width; j++) {
            if (map[j][i] == '1')
            //----              SFML             ----//
                this->stuff.wall.setPosition(i*this->tall, j*this->tall);
        this->stuff.window.draw(this->stuff.wall);
        //----              SFML             ----// 
    }

    for (int i = 0; i < this->num; i++) {
        //----              SFML             ----// 
        this->stuff.pacman.setPosition(cell[i].x*this->tall, cell[i].y*this->tall);
        this->stuff.window.draw(this->stuff.pacman);
        }
    this->stuff.window.display();
    //----              SFML             ----//
}

int main()
{
    Pacman p;
    p.setMap();
    p.init();
    while(p.conditionClose()) {
        p.timing();
        p.eventHandler();
        p.move();
        p.refresh();
        p.display();
    }

}