/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Error
*/

#include "Error.hpp"

Error::Error(const std::string &msg, const size_t value)
        : _msg(msg), _value(value)
{
}

Error::~Error()
{
}

const char *Error::what() const throw()
{
    return _msg.c_str();
}

size_t Error::getErrorValue() const
{
    return _value;
}