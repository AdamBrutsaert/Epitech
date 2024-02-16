/*
** EPITECH PROJECT, 2024
** WarpSystem.hpp
** File description:
** WarpSystem.hpp
*/

#pragma once

namespace WarpSystem {
    class QuantumReactor {
    public:
        QuantumReactor();
        ~QuantumReactor() = default;

        bool isStable() { return this->_stability; }
        void setStability(bool stability) { this->_stability = stability; }
    private:
        bool _stability;
    };

    class Core {
    public:
        Core(QuantumReactor *coreReactor);
        ~Core() = default;

        QuantumReactor *checkReactor() { return this->_coreReactor; }
    private:
        QuantumReactor *_coreReactor;
    };
}
