/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

//Trello : https://trello.com/invite/b/0S47T6Rv/270bcb2b0bc4a1e51355ca38d4adf64d/ooparcade2019

#include "ICore.hpp"

void print_usage()
{
    std::cerr << "USAGE:" << std::endl << "\t./arcade <graphical library>" << std::endl;
}

int check_lib(std::string &filename)
{
    if (filename.substr(filename.find_last_of('.') + 1) == "so")
        return start_arcade(filename);
    std::cerr << "Argument must be a dynamic library (.so file)" << std::endl;
    return 84;
}

int check_args(int ac, char **av)
{
    if (ac != 2) {
        print_usage();
        return 84;
    } else if (ac == 2) {
        std::ifstream lib_name(av[1]);
        std::string filename(av[1]);
        if (!lib_name.good()) {
            std::ifstream lib_name_c("./lib/" + std::string(av[1]));
            filename = "./lib/" + std::string(av[1]);
            if (!lib_name_c.good()) {
                print_usage();
                return 84;
            }
        }
        if (check_lib(filename) != 0) {
            print_usage();
            return 84;
        }
    }
    return 0;
}

int main(int ac, char **av)
{
    return check_args(ac, av);
}