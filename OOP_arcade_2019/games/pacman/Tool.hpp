/*
** EPITECH PROJECT, 2020
** pacman
** File description:
** Tool
*/

#ifndef TOOL_HPP_
#define TOOL_HPP_

#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

class Tool {
    public:
        Tool();
        ~Tool();

        char **strlist(const std::vector<std::string> &input);
        void del_strlist(char *const *strings);
        std::vector<std::string> openmafile(std::string file_name);
        void init_lib();

    protected:
    private:
};

#endif /* !TOOL_HPP_ */
