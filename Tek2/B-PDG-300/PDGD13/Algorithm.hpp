/*
** EPITECH PROJECT, 2024
** Algorithm.hpp
** File description:
** Algorithm.hpp
*/

#pragma once

template<typename T>
void swap(T& a, T& b)
{
    T tmp = a;

    a = b;
    b = tmp;
}

template<typename T>
T min(T a, T b)
{
    return a < b ? a : b;
}

template<typename T>
T max(T a, T b)
{
    return a < b ? b : a;
}

template<typename T>
T clamp(T value, T min, T max)
{
    return ::min<T>(::max<T>(value, min), max);
}
