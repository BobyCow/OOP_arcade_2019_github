/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <string>

#define WRONG_ARGUMENT  1
#define ERROR_HANDLER   2
#define ERROR_DLSYM     3

class Error : public std::exception
{
    public:
        Error(const std::string &msg, const size_t value /*Error Macro*/);
        ~Error();
        virtual const char *what() const throw();
        size_t getErrorValue() const;
    protected:
    private:
        std::string _msg;
        size_t _value;

};

#endif /* !ERROR_HPP_ */
