/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Loop
*/


#ifndef ICORE_HPP_
#define ICORE_HPP_

#include <iostream>
#include <fstream>
#include <dlfcn.h>
#include <memory>
#include "Menu.hpp"

class ICore {
    public:
        virtual ~ICore() {};
        virtual void launch() = 0;
    protected:
    private:
        //std::unique_ptr<IGame> game;
};

int start_arcade(const std::string &filename);

#endif /* !ICORE_HPP_ */
