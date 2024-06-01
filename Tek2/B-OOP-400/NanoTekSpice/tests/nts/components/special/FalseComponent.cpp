/*
** EPITECH PROJECT, 2024
** FalseComponent.cpp
** File description:
** FalseComponent.cpp
*/

#include "nts/components/special/FalseComponent.hpp"

#include <criterion/criterion.h>

Test(FalseComponent, false)
{
    nts::FalseComponent c1;

    cr_assert_eq(c1.pin(1).state(), nts::Tristate::False);
    cr_assert_eq(c1.pin(1).type(), nts::Pin::Type::Output);

    c1.tick();
    cr_assert_eq(c1.pin(1).state(), nts::Tristate::False);

    cr_assert_throw(c1.pin(0), nts::IComponent::InvalidPin);
    cr_assert_throw(c1.pin(2), nts::IComponent::InvalidPin);
}
