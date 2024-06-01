/*
** EPITECH PROJECT, 2024
** NorComponent.cpp
** File description:
** NorComponent.cpp
*/

#include "nts/components/elementary/NorComponent.hpp"

#include <criterion/criterion.h>

#define CHECK(a, b, expected) \
    do { \
        i1.set(a); \
        i2.set(b); \
        cr_assert_eq(c1.pin(3).state(), expected); \
        c1.tick(); \
        cr_assert_eq(c1.pin(3).state(), expected); \
    } while (0);

Test(NorComponent, nor)
{
    using nts::Tristate;

    nts::Pin i1(nts::Pin::Type::Output);
    nts::Pin i2(nts::Pin::Type::Output);
    nts::NorComponent c1;

    c1.pin(1).link(i1);
    c1.pin(2).link(i2);

    cr_assert_eq(i1.state(), Tristate::Undefined);
    cr_assert_eq(i2.state(), Tristate::Undefined);
    cr_assert_eq(c1.pin(3).state(), Tristate::Undefined);

    CHECK(Tristate::False, Tristate::False, Tristate::True);
    CHECK(Tristate::False, Tristate::True, Tristate::False);
    CHECK(Tristate::False, Tristate::Undefined, Tristate::Undefined);
    CHECK(Tristate::True, Tristate::False, Tristate::False);
    CHECK(Tristate::True, Tristate::True, Tristate::False);
    CHECK(Tristate::True, Tristate::Undefined, Tristate::False);
    CHECK(Tristate::Undefined, Tristate::False, Tristate::Undefined);
    CHECK(Tristate::Undefined, Tristate::True, Tristate::False);
    CHECK(Tristate::Undefined, Tristate::Undefined, Tristate::Undefined);

    cr_assert_throw(c1.pin(0), nts::IComponent::InvalidPin);
    cr_assert_throw(c1.pin(4), nts::IComponent::InvalidPin);
}
