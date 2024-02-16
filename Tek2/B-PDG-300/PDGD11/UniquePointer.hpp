/*
** EPITECH PROJECT, 2024
** UniquePointer.hpp
** File description:
** UniquePointer.hpp
*/

#pragma once

#include "IObject.hpp"

class UniquePointer {
public:
    UniquePointer(IObject *ptr = nullptr);
    UniquePointer(const UniquePointer &other) = delete;
    UniquePointer(UniquePointer &&other);
    UniquePointer &operator=(const UniquePointer &other) = delete;
    UniquePointer &operator=(UniquePointer &&other);
    UniquePointer &operator=(IObject *ptr);
    ~UniquePointer();

    IObject &operator*() const;
    IObject *operator->() const;

    void reset(IObject *ptr = nullptr);
    void swap(UniquePointer &other);

private:
    IObject *_ptr;
};
