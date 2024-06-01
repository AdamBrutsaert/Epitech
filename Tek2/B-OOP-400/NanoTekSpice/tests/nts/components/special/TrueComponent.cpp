/*
** EPITECH PROJECT, 2024
** TrueComponent.cpp
** File description:
** TryeComponent.cpp
*/

#include "nts/components/special/TrueComponent.hpp"

#include <criterion/criterion.h>

Test(TrueComponent, true)
{
    nts::TrueComponent c1;

    cr_assert_eq(c1.pin(1).state(), nts::Tristate::True);
    cr_assert_eq(c1.pin(1).type(), nts::Pin::Type::Output);

    c1.tick();
    cr_assert_eq(c1.pin(1).state(), nts::Tristate::True);

    cr_assert_throw(c1.pin(0), nts::IComponent::InvalidPin);
    cr_assert_throw(c1.pin(2), nts::IComponent::InvalidPin);
}
