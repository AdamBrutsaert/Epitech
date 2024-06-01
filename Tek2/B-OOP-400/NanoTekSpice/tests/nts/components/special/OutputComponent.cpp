/*
** EPITECH PROJECT, 2024
** OutputComponent.cpp
** File description:
** OutputComponent.cpp
*/

#include "nts/components/special/OutputComponent.hpp"

#include <criterion/criterion.h>

Test(OutputComponent, output)
{
    nts::OutputComponent c1;

    cr_assert_eq(c1.pin(1).state(), nts::Tristate::Undefined);
    cr_assert_eq(c1.pin(1).type(), nts::Pin::Type::Input);

    c1.tick();
    cr_assert_eq(c1.pin(1).state(), nts::Tristate::Undefined);

    cr_assert_throw(c1.pin(0), nts::IComponent::InvalidPin);
    cr_assert_throw(c1.pin(2), nts::IComponent::InvalidPin);
}
