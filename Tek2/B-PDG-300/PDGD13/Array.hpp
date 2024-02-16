/*
** EPITECH PROJECT, 2024
** Array.hpp
** File description:
** Array.hpp
*/

#pragma once

#include <array>
#include <functional>
#include <iostream>
#include <stdexcept>

template<typename Type, std::size_t Size>
class Array {
public:
    Array()
    {
        for (std::size_t i = 0; i < Size; i++)
            this->_array[i] = Type{};
    }

    ~Array() = default;

    Type& operator[](std::size_t index)
    {
        if (index >= Size)
            throw std::out_of_range("Out of range");

        return this->_array[index];
    }

    const Type& operator[](std::size_t index) const
    {
        if (index >= Size)
            throw std::out_of_range("Out of range");

        return this->_array[index];
    }

    std::size_t size() const
    {
        return Size;
    }

    void forEach(const std::function<void(const Type&)>& task) const
    {
        for (std::size_t i = 0; i < Size; i++)
            task(this->_array[i]);
    }

    template<typename U>
    Array<U, Size> convert(const std::function<U(const Type&)>& converter) const
    {
        Array<U, Size> array;

        for (std::size_t i = 0; i < Size; i++)
            array[i] = converter(this->_array[i]);

        return array;
    }

private:
    std::array<Type, Size> _array;
};

template<typename Type, std::size_t Size>
std::ostream &operator<<(std::ostream &os, const Array<Type, Size> &array)
{
    os << "[";

    for (std::size_t i = 0; i < Size; i++) {
        if (i != 0) os << ", ";
        os << array[i];
    }

    return os << "]";
}
