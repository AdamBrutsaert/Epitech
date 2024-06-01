/*
** EPITECH PROJECT, 2024
** SharedLibrary.cpp
** File description:
** SharedLibrary.cpp
*/

#include "libraries/SharedLibrary.hpp"

namespace core {
    SharedLibrary::SharedLibrary()
        : _handle(nullptr), _path("")
    {
    }

    SharedLibrary::SharedLibrary(const std::string &path)
        : _handle(nullptr), _path("")
    {
        this->open(path);
    }

    SharedLibrary::~SharedLibrary()
    {
        this->close();
    }

    SharedLibrary::SharedLibrary(const SharedLibrary &other)
        : _handle(nullptr), _path("")
    {
        this->open(other._path);
    }

    SharedLibrary &SharedLibrary::operator=(const SharedLibrary &other)
    {
        this->open(other._path);
        return *this;
    }

    SharedLibrary::SharedLibrary(SharedLibrary &&other)
    {
        if (this == &other)
            return;

        this->_handle = other._handle;
        this->_path = other._path;

        other._handle = nullptr;
        other._path = "";
    }

    SharedLibrary &SharedLibrary::operator=(SharedLibrary &&other)
    {
        if (this == &other)
            return *this;

        this->_handle = other._handle;
        this->_path = other._path;

        other._handle = nullptr;
        other._path = "";

        return *this;
    }

    bool SharedLibrary::open(const std::string &path)
    {
        this->close();

        this->_handle = dlopen(path.c_str(), RTLD_LAZY);

        if (this->_handle == nullptr) {
            std::cerr << dlerror() << std::endl;
            return false;
        }

        this->_path = path;
        return true;
    }

    bool SharedLibrary::close()
    {
        if (this->_handle == nullptr)
            return false;

        if (dlclose(this->_handle) != 0) {
            std::cerr << dlerror() << std::endl;
            return false;
        }

        this->_handle = nullptr;
        this->_path = "";

        return true;
    }

    const std::string &SharedLibrary::path() const
    {
        return this->_path;
    }
}
