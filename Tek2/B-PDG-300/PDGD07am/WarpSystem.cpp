/*
** EPITECH PROJECT, 2024
** WarpSystem.cpp
** File description:
** WarpSystem.cpp
*/

#include "WarpSystem.hpp"

namespace WarpSystem {
    QuantumReactor::QuantumReactor()
        : _stability(true)
    {
    }

    Core::Core(QuantumReactor *coreReactor)
        : _coreReactor(coreReactor)
    {
    }
}
