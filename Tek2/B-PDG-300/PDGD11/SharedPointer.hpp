/*
** EPITECH PROJECT, 2024
** SharedPointer.hpp
** File description:
** SharedPointer.hpp
*/

#pragma once

#include "IObject.hpp"

#include <cstddef>

class SharedPointer {
public:
    SharedPointer(IObject *ptr = nullptr);
    SharedPointer(const SharedPointer &other);
    SharedPointer(SharedPointer &&other) = delete;
    SharedPointer &operator=(const SharedPointer &other);
    SharedPointer &operator=(IObject *ptr);
    SharedPointer &operator=(SharedPointer &&other) = delete;
    ~SharedPointer();

    IObject &operator*() const;
    IObject *operator->() const;

    std::size_t use_count() const;
    void reset(IObject *ptr = nullptr);
    void swap(SharedPointer &other);

private:
    std::size_t *_count;
    IObject *_ptr;
};
