/*
** EPITECH PROJECT, 2024
** InputComponent.cpp
** File description:
** InputComponent.cpp
*/

#include "nts/components/special/InputComponent.hpp"

#include <criterion/criterion.h>

Test(InputComponent, input)
{
    nts::InputComponent c1;

    cr_assert_eq(c1.pin(1).state(), nts::Tristate::Undefined);
    cr_assert_eq(c1.pin(1).type(), nts::Pin::Type::Output);

    c1.tick();
    cr_assert_eq(c1.pin(1).state(), nts::Tristate::Undefined);

    cr_assert_throw(c1.pin(0), nts::IComponent::InvalidPin);
    cr_assert_throw(c1.pin(2), nts::IComponent::InvalidPin);
}
