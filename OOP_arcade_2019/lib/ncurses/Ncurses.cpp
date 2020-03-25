/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Ncurse
*/

#include "Ncurses.hpp"

short check_color(int fg)
{
    switch (7 & fg) {
        case 1:
            return (COLOR_WHITE);
        case 2:
            return (COLOR_RED);
        case 3:
            return (COLOR_GREEN);
        case 4:
            return (COLOR_BLUE);
        case 5:
            return (COLOR_YELLOW);
        case 6:
            return (COLOR_MAGENTA);
        case 7:
            return (COLOR_CYAN);
        default:
            return (COLOR_BLACK);
    }
}

int colornum(int fg, int bg)
{
    int B;
    int bbb;
    int ffff;

    B = 1 << 7;
    bbb = (7 & bg) << 4;
    ffff = 7 & fg;

    return (B | bbb | ffff);
}

void init_colorpairs(void)
{
    int fg;
    int bg;
    int colorpair;

    for (bg = 0; bg <= 7; bg++)
        for (fg = 0; fg <= 7; fg++) {
            colorpair = colornum(fg, bg);
            init_pair(colorpair, check_color(fg), check_color(bg));
        }
}

Ncurses::Ncurses()
{
    std::cout << "NCURSES object created !" << std::endl;
    window = initscr();
    cbreak();
    // int x = 0; int y = 0;
    // getmaxyx(window, y, x);
    // std::cout << "x: " << x << "\ty: " << y << std::endl;
    // // wresize(this->window, 1700, 1000);
    // resize_term(1000, 1700);
    // getmaxyx(window, y, x);
    // std::cout << "x: " << x << "\ty: " << y << std::endl;
    keypad(window, true);
    noecho();
    start_color();
    init_colorpairs();
}

Ncurses::~Ncurses()
{
    endwin();
    std::cout << "NCURSES object deleted !" << std::endl;
}

void Ncurses::display_window()
{
    refresh();
}

char Ncurses::check_event()
{
    char c = getch();

    switch (c) {
        case 'z':
            return c;
        case 'q':
            return c;
        case 's':
            return c;
        case 'd':
            return c;
        case 'g':
            delete this;
            return c;
        case 27:
            delete this;
            return c;
        default:
            return c;
    }
}

void Ncurses::display_text(const std::string &text, float x, float y, float size, int color)
{
    (void) size;

    attron(COLOR_PAIR(colornum(color, 0)));
    mvwprintw(window, (y * 50) / 1000, (x * 200) / 1700, text.c_str());
    attroff(COLOR_PAIR(colornum(color, 0)));
}

void Ncurses::display_text(const std::string &text, float x, float y)
{
    mvwprintw(window, (y * 100) / 1000, (x * 100) / 1700, text.c_str());
}

extern "C"
{
    IGraph *create()
    {
        return new Ncurses();
    }
}