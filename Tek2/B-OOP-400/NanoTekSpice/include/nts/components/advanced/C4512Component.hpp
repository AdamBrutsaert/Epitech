/*
** EPITECH PROJECT, 2024
** C4512Component.hpp
** File description:
** C4512Component.hpp
*/

#include "nts/components/IComponent.hpp"

namespace nts {
    class C4512Component : public IComponent {
    public:
        C4512Component();
        virtual ~C4512Component() override = default;

        virtual void tick() override;
        virtual Pin& pin(std::size_t pin) override;

    private:
        void update();

    private:
        std::vector<Pin> _inputs;
        std::vector<Pin> _address;
        Pin _inhibit;
        Pin _disable;
        Pin _output;
    };
}
