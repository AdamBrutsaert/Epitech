/*
** EPITECH PROJECT, 2024
** SharedLibrary.hpp
** File description:
** SharedLibrary.hpp
*/

#pragma once

#include <string>
#include <iostream>
#include <dlfcn.h>

namespace core {
    class SharedLibrary {
    public:

        // Constructors & Destructor
        SharedLibrary();
        SharedLibrary(const std::string &path);
        virtual ~SharedLibrary();

        // Copy constructor and copy assignment operator
        SharedLibrary(const SharedLibrary &other);
        SharedLibrary &operator=(const SharedLibrary &other);

        // Move constructor and move assignment operator
        SharedLibrary(SharedLibrary &&other);
        SharedLibrary &operator=(SharedLibrary &&other);

        // Open & Close
        bool open(const std::string &path);
        virtual bool close();

        // Path & Symbol & Get
        const std::string& path() const;

        template<typename T>
        T symbol(const std::string &symbol, T defaultValue) const
        {
            if (_handle == nullptr)
                return defaultValue;

            auto func = reinterpret_cast<T>(dlsym(_handle, symbol.c_str()));

            if (func == nullptr) {
                std::cerr << dlerror() << std::endl;
                return defaultValue;
            }

            return func;
        }

        template<typename T>
        T get(const std::string &symbol, T defaultValue) const
        {
            auto sym = this->symbol<T (*)()>(symbol, nullptr);

            if (sym == nullptr)
                return defaultValue;

            return sym();
        }

    private:
        void *_handle;
        std::string _path;
    };
}
