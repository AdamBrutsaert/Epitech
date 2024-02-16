/*
** EPITECH PROJECT, 2024
** Federation.hpp
** File description:
** Federation.hpp
*/

#pragma once

#include <string>

#include "WarpSystem.hpp"
#include "Destination.hpp"
#include "Borg.hpp"

namespace Federation::Starfleet {
    class Captain {
    public:
        Captain(std::string name);
        ~Captain() = default;

        std::string getName(void) { return this->_name; }
        int getAge(void) { return this->_age; }
        void setAge(int age) { this->_age = age; }
    private:
        std::string _name;
        int _age;
    };

    class Ensign {
    public:
        explicit Ensign(std::string name);
        ~Ensign() = default;
    private:
        std::string _name;
    };

    class Ship {
    public:
        Ship(int length = 289, int width = 132, std::string nam = "Entreprise", short maxWarp = 6, int torpedo = 0);
        virtual ~Ship() = default;

        void setupCore(WarpSystem::Core *core);
        void checkCore(void);

        void promote(Captain *captain);

        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();

        int getShield() { return this->_shield; }
        void setShield(int shield) { this->_shield = shield; }
        int getTorpedo() { return this->_photonTorpedo; }
        void setTorpedo(int torpedo) { this->_photonTorpedo = torpedo; }

        void fire(Borg::Ship *target);
        void fire(int torpedoes, Borg::Ship *target);
    private:
        int _length;
        int _width;
        std::string _name;
        short _maxWarp;
        WarpSystem::Core *_core;
        Captain *_captain;
        Destination _home;
        Destination _location;
        int _shield;
        int _photonTorpedo;
    };
}

namespace Federation {
    class Ship {
    public:
        Ship(int length, int width, std::string name);
        ~Ship() = default;

        void setupCore(WarpSystem::Core *core);
        void checkCore(void);
        WarpSystem::Core *getCore(void) { return this->_core; }

        bool move(int warp, Destination d);
        bool move(int warp);
        bool move(Destination d);
        bool move();
    private:
        int _length;
        int _width;
        std::string _name;
        int _maxWarp;
        WarpSystem::Core *_core;
        Destination _home;
        Destination _location;
    };
}
