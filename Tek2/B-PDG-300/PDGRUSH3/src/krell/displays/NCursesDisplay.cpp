/*
** EPITECH PROJECT, 2024
** NCursesDisplay.cpp
** File description:
** NCursesDisplay.cpp
*/

#include "krell/displays/NCursesDisplay.hpp"

#include <sys/ioctl.h>

namespace Krell {
    NCursesDisplay::NCursesDisplay()
        : _shouldClose(false)
    {
        // Initialize default window
        initscr();

        // Allow user to suspend program with Ctrl-Z
        // or terminate with Ctrl-C
        cbreak();

        // Disable echoing of typed characters
        noecho();

        // Enable detection of special keys (arrows, F<number>, etc...)
        keypad(stdscr, TRUE);

        // Colors
        start_color();
        use_default_colors();

        // Colors pairs
        init_pair(1, COLOR_GREEN, -1);
        init_pair(2, COLOR_RED, -1);
        init_pair(3, COLOR_MAGENTA, -1);
        init_pair(4, COLOR_YELLOW, -1);
    }

    NCursesDisplay::~NCursesDisplay()
    {
        endwin();
    }

    void NCursesDisplay::close()
    {
        this->_shouldClose = true;
    }

    bool NCursesDisplay::shouldClose() const
    {
        return this->_shouldClose;
    }

    void NCursesDisplay::pollEvents()
    {
        float deltaTime = this->_clock.restart().asSeconds();
        int wait = std::max(0, (int)(33 - deltaTime * 1000));

        timeout(wait);
        int ch = getch();

        if (ch != ERR)
            this->onKeyReleased(this->_mapKey(ch));
    }

    void NCursesDisplay::clear()
    {
    }

    void NCursesDisplay::forceClear()
    {
        ::clear();
    }

    void NCursesDisplay::display()
    {
        refresh();
    }

    Width NCursesDisplay::getWidth() const
    {
        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);
        return w.ws_col;
    }

    sf::Keyboard::Key NCursesDisplay::_mapKey(int code) const
    {
        switch (code)
        {
            case 'a': return sf::Keyboard::A;
            case 'b': return sf::Keyboard::B;
            case 'c': return sf::Keyboard::C;
            case 'd': return sf::Keyboard::D;
            case 'e': return sf::Keyboard::E;
            case 'f': return sf::Keyboard::F;
            case 'g': return sf::Keyboard::G;
            case 'h': return sf::Keyboard::H;
            case 'i': return sf::Keyboard::I;
            case 'j': return sf::Keyboard::J;
            case 'k': return sf::Keyboard::K;
            case 'l': return sf::Keyboard::L;
            case 'm': return sf::Keyboard::M;
            case 'n': return sf::Keyboard::N;
            case 'o': return sf::Keyboard::O;
            case 'p': return sf::Keyboard::P;
            case 'q': return sf::Keyboard::Q;
            case 'r': return sf::Keyboard::R;
            case 's': return sf::Keyboard::S;
            case 't': return sf::Keyboard::T;
            case 'u': return sf::Keyboard::U;
            case 'v': return sf::Keyboard::V;
            case 'w': return sf::Keyboard::W;
            case 'x': return sf::Keyboard::X;
            case 'y': return sf::Keyboard::Y;
            case 'z': return sf::Keyboard::Z;
            case '0': return sf::Keyboard::Num0;
            case '1': return sf::Keyboard::Num1;
            case '2': return sf::Keyboard::Num2;
            case '3': return sf::Keyboard::Num3;
            case '4': return sf::Keyboard::Num4;
            case '5': return sf::Keyboard::Num5;
            case '6': return sf::Keyboard::Num6;
            case '7': return sf::Keyboard::Num7;
            case '8': return sf::Keyboard::Num8;
            case '9': return sf::Keyboard::Num9;
            case 27: return sf::Keyboard::Escape;
            case 9: return sf::Keyboard::Tab;
            case 32: return sf::Keyboard::Space;
            case KEY_UP: return sf::Keyboard::Up;
            case KEY_DOWN: return sf::Keyboard::Down;
            case KEY_LEFT: return sf::Keyboard::Left;
            case KEY_RIGHT: return sf::Keyboard::Right;
            default: return sf::Keyboard::Unknown;
        }
    }
}
