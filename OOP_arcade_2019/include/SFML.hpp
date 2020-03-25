/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include "IGraph.hpp"
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Config.hpp>

class SFML : public IGraph
{
    public:
        SFML();
        virtual ~SFML();
        virtual void display_window() final;
        virtual char check_event() final;
        virtual void display_text(const std::string &text, float x, float y) final;
        virtual void display_text(const std::string &text, float x, float y, float size, int color) final;
        virtual std::size_t display_menu() final;
        sf::Color check_color(int color);
        void display_menu_choices(size_t *cursor);
    protected:
    private:
        sf::RenderWindow _win;
};

#endif /* !SFML_HPP_ */
