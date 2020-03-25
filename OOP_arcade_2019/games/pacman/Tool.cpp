/*
** EPITECH PROJECT, 2020
** pacman
** File description:
** Tool
*/

#include "Tool.hpp"

Tool::Tool()
{
}

Tool::~Tool()
{
}

char **Tool::strlist(const std::vector<std::string>& input)
{
    char **result = new char*[input.size() + 1];
    size_t storage_size = 0;
    for (auto const& s: input) {
        storage_size += s.size() + 1;
    }

    try {
        char *storage = new char[storage_size];
        char *p = storage;
        char **q = result;
        for (auto const& s: input) {
            *q++ = strcpy(p, s.c_str());
            p += s.size() + 1;
        }
        *q = nullptr;

        return result;
    }
    catch (...) {
        delete[] result;
        throw;
    }
}

void Tool::del_strlist(char *const *strings)
{
    delete[] strings[0];
    delete[] strings;
}

std::vector<std::string> Tool::openmafile(std::string file_name)
{
    std::vector<std::string> text;
    std::string line;

    std::ifstream input_stream(file_name);
    if (!input_stream) 
        std::cerr << "Can't open input file!";
        
    while (getline(input_stream, line)) {
        text.push_back(line);
        }
    //---- to display : unlock this ----//
    /*for (long unsigned int i = 0; i < text.size(); i++)
        cout << text[i] << "\n";*/
    return (text);
}