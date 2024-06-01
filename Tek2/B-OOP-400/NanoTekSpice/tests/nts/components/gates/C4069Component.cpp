/*
** EPITECH PROJECT, 2024
** C4069Component.cpp
** File description:
** C4069Component.cpp
*/

#include "nts/components/gates/C4069Component.hpp"

#include <criterion/criterion.h>

#define CHECK(a, expected) \
    do { \
        i1.set(a); \
        cr_assert_eq(o1.state(), expected); \
        c1.tick(); \
        cr_assert_eq(o1.state(), expected); \
    } while (0);

static void check(nts::C4069Component& c1, std::size_t in1, std::size_t out1)
{
    using nts::Tristate;

    nts::Pin& i1 = c1.pin(in1);
    nts::Pin& o1 = c1.pin(out1);

    cr_assert_eq(i1.state(), Tristate::Undefined);
    cr_assert_eq(o1.state(), Tristate::Undefined);

    CHECK(Tristate::False, Tristate::True);
    CHECK(Tristate::True, Tristate::False);
    CHECK(Tristate::Undefined, Tristate::Undefined);
}

Test(C4069Component, 4069)
{
    nts::C4069Component c1;

    check(c1, 1, 2);
    check(c1, 3, 4);
    check(c1, 5, 6);
    check(c1, 9, 8);
    check(c1, 11, 10);
    check(c1, 13, 12);

    cr_assert_throw(c1.pin(0), nts::IComponent::InvalidPin);
    cr_assert_throw(c1.pin(7), nts::IComponent::InvalidPin);
    cr_assert_throw(c1.pin(14), nts::IComponent::InvalidPin);
}
