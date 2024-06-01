/*
** EPITECH PROJECT, 2024
** C4011Component.cpp
** File description:
** C4011Component.cpp
*/

#include "nts/components/gates/C4011Component.hpp"

#include <criterion/criterion.h>

#define CHECK(a, b, expected) \
    do { \
        i1.set(a); \
        i2.set(b); \
        cr_assert_eq(o1.state(), expected); \
        c1.tick(); \
        cr_assert_eq(o1.state(), expected); \
    } while (0);

static void check(nts::C4011Component& c1, std::size_t in1, std::size_t in2, std::size_t out1)
{
    using nts::Tristate;

    nts::Pin& i1 = c1.pin(in1);
    nts::Pin& i2 = c1.pin(in2);
    nts::Pin& o1 = c1.pin(out1);

    cr_assert_eq(i1.state(), Tristate::Undefined);
    cr_assert_eq(i2.state(), Tristate::Undefined);
    cr_assert_eq(o1.state(), Tristate::Undefined);

    CHECK(Tristate::False, Tristate::False, Tristate::True);
    CHECK(Tristate::False, Tristate::True, Tristate::True);
    CHECK(Tristate::False, Tristate::Undefined, Tristate::True);
    CHECK(Tristate::True, Tristate::False, Tristate::True);
    CHECK(Tristate::True, Tristate::True, Tristate::False);
    CHECK(Tristate::True, Tristate::Undefined, Tristate::Undefined);
    CHECK(Tristate::Undefined, Tristate::False, Tristate::True);
    CHECK(Tristate::Undefined, Tristate::True, Tristate::Undefined);
    CHECK(Tristate::Undefined, Tristate::Undefined, Tristate::Undefined);
}

Test(C4011Component, 4011)
{
    nts::C4011Component c1;

    check(c1, 1, 2, 3);
    check(c1, 5, 6, 4);
    check(c1, 8, 9, 10);
    check(c1, 12, 13, 11);

    cr_assert_throw(c1.pin(0), nts::IComponent::InvalidPin);
    cr_assert_throw(c1.pin(7), nts::IComponent::InvalidPin);
    cr_assert_throw(c1.pin(14), nts::IComponent::InvalidPin);
}
