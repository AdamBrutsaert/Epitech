/*
** EPITECH PROJECT, 2024
** SharedPointer.cpp
** File description:
** SharedPointer.cpp
*/

#include "SharedPointer.hpp"

SharedPointer::SharedPointer(IObject *ptr)
    : _ptr(ptr)
{
    if (ptr == nullptr) {
        this->_count = nullptr;
    } else {
        this->_count = new std::size_t(1);
    }
}

SharedPointer::SharedPointer(const SharedPointer &other)
    : _count(other._count), _ptr(other._ptr)
{
    if (this->_count != nullptr)
        (*this->_count)++;
}

SharedPointer &SharedPointer::operator=(const SharedPointer &other)
{
    if (this->_ptr == other._ptr)
        return *this;

    if (this->_ptr != nullptr) {
        (*this->_count)--;
        if (this->_count == 0) {
            delete this->_ptr;
            delete this->_count;
        }
    }

    this->_ptr = other._ptr;
    this->_count = other._count;

    if (this->_count != nullptr)
        (*this->_count)++;

    return *this;
}

SharedPointer &SharedPointer::operator=(IObject *ptr)
{
    if (this->_ptr == ptr)
        return *this;

    if (this->_ptr != nullptr) {
        (*this->_count)--;
        if (*this->_count == 0) {
            delete this->_ptr;
            delete this->_count;
        }
    }

    this->_ptr = ptr;

    if (ptr == nullptr) {
        this->_count = nullptr;
    } else {
        this->_count = new std::size_t(1);
    }
    return *this;
}

SharedPointer::~SharedPointer()
{
    if (this->_count != nullptr) {
        (*this->_count)--;
        if (*this->_count == 0) {
            delete this->_ptr;
            delete this->_count;
        }
    }
}

IObject &SharedPointer::operator*() const
{
    return *this->_ptr;
}

IObject *SharedPointer::operator->() const
{
    return this->_ptr;
}

std::size_t SharedPointer::use_count() const
{
    if (this->_count == nullptr)
        return 0;
    return *this->_count;
}

void SharedPointer::reset(IObject *ptr)
{
    if (this->_ptr == ptr)
        return;

    if (this->_ptr != nullptr) {
        (*this->_count)-- ;
        if (*this->_count == 0) {
            delete this->_ptr;
            delete this->_count;
        }
    }

    this->_ptr = ptr;

    if (ptr == nullptr) {
        this->_count = nullptr;
    } else {
        this->_count = new std::size_t(1);
    }
}

void SharedPointer::swap(SharedPointer &other)
{
    IObject *tmp = this->_ptr;
    std::size_t *tmp_count = this->_count;

    this->_ptr = other._ptr;
    this->_count = other._count;

    other._ptr = tmp;
    other._count = tmp_count;
}
