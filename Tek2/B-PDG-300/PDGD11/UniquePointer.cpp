/*
** EPITECH PROJECT, 2024
** UniquePointer.cpp
** File description:
** UniquePointer.cpp
*/

#include "UniquePointer.hpp"

UniquePointer::UniquePointer(IObject *ptr)
    : _ptr(ptr)
{
}

UniquePointer::UniquePointer(UniquePointer &&other)
    : _ptr(other._ptr)
{
    other._ptr = nullptr;
}

UniquePointer::~UniquePointer()
{
    if (_ptr != nullptr)
        delete this->_ptr;
}

UniquePointer &UniquePointer::operator=(IObject *ptr)
{
    if (this->_ptr != nullptr)
        delete this->_ptr;
    this->_ptr = ptr;
    return *this;
}

UniquePointer &UniquePointer::operator=(UniquePointer &&other)
{
    if (this->_ptr != nullptr)
        delete this->_ptr;
    this->_ptr = other._ptr;
    other._ptr = nullptr;
    return *this;
}

IObject &UniquePointer::operator*() const
{
    return *this->_ptr;
}

IObject *UniquePointer::operator->() const
{
    return this->_ptr;
}

void UniquePointer::reset(IObject *ptr)
{
    if (this->_ptr != nullptr)
        delete this->_ptr;
    this->_ptr = ptr;
}

void UniquePointer::swap(UniquePointer &other)
{
    IObject *tmp = this->_ptr;

    this->_ptr = other._ptr;
    other._ptr = tmp;
}
