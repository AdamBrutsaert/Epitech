/*
** EPITECH PROJECT, 2024
** ClockComponent.cpp
** File description:
** ClockComponent.cpp
*/

#include "nts/components/special/ClockComponent.hpp"

#include <criterion/criterion.h>

Test(ClockComponent, clock)
{
    nts::ClockComponent c1;

    cr_assert_eq(c1.pin(1).state(), nts::Tristate::Undefined);
    cr_assert_eq(c1.pin(1).type(), nts::Pin::Type::Output);

    c1.tick();
    cr_assert_eq(c1.pin(1).state(), nts::Tristate::Undefined);

    c1.pin(1).set(nts::Tristate::True);
    cr_assert_eq(c1.pin(1).state(), nts::Tristate::True);

    c1.tick();
    cr_assert_eq(c1.pin(1).state(), nts::Tristate::False);

    c1.tick();
    cr_assert_eq(c1.pin(1).state(), nts::Tristate::True);

    c1.pin(1).set(nts::Tristate::False);
    cr_assert_eq(c1.pin(1).state(), nts::Tristate::False);

    c1.tick();
    cr_assert_eq(c1.pin(1).state(), nts::Tristate::True);

    c1.tick();
    cr_assert_eq(c1.pin(1).state(), nts::Tristate::False);

    cr_assert_throw(c1.pin(0), nts::IComponent::InvalidPin);
    cr_assert_throw(c1.pin(2), nts::IComponent::InvalidPin);
}
