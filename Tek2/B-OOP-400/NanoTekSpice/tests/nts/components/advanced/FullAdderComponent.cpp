/*
** EPITECH PROJECT, 2024
** FullAdderComponent.cpp
** File description:
** FullAdderComponent.cpp
*/

#include "nts/components/advanced/FullAdderComponent.hpp"

#include <criterion/criterion.h>

#define CHECK(a, b, c, e1, e2) \
    do { \
        operand_a.set(a); \
        operand_b.set(b); \
        carry_in.set(c); \
        cr_assert_eq(c1.pin(4).state(), e1); \
        cr_assert_eq(c1.pin(5).state(), e2); \
        c1.tick(); \
        cr_assert_eq(c1.pin(4).state(), e1); \
        cr_assert_eq(c1.pin(5).state(), e2); \
    } while (0);

Test(FullAdderComponent, full_adder)
{
    using nts::Tristate;

    nts::Pin operand_a(nts::Pin::Type::Output);
    nts::Pin operand_b(nts::Pin::Type::Output);
    nts::Pin carry_in(nts::Pin::Type::Output);
    nts::FullAdderComponent c1;

    c1.pin(1).link(operand_a);
    c1.pin(2).link(operand_b);
    c1.pin(3).link(carry_in);

    cr_assert_eq(operand_a.state(), Tristate::Undefined);
    cr_assert_eq(operand_b.state(), Tristate::Undefined);
    cr_assert_eq(carry_in.state(), Tristate::Undefined);
    cr_assert_eq(c1.pin(4).state(), Tristate::Undefined);
    cr_assert_eq(c1.pin(5).state(), Tristate::Undefined);

    operand_a.set(Tristate::False);
    operand_b.set(Tristate::False);
    carry_in.set(Tristate::False);

    CHECK(Tristate::False, Tristate::False, Tristate::False, Tristate::False, Tristate::False);
    CHECK(Tristate::False, Tristate::False, Tristate::True, Tristate::True, Tristate::False);

    CHECK(Tristate::False, Tristate::True, Tristate::False, Tristate::True, Tristate::False);
    CHECK(Tristate::False, Tristate::True, Tristate::True, Tristate::False, Tristate::True);

    CHECK(Tristate::True, Tristate::False, Tristate::False, Tristate::True, Tristate::False);
    CHECK(Tristate::True, Tristate::False, Tristate::True, Tristate::False, Tristate::True);

    CHECK(Tristate::True, Tristate::True, Tristate::False, Tristate::False, Tristate::True);
    CHECK(Tristate::True, Tristate::True, Tristate::True, Tristate::True, Tristate::True);

    cr_assert_throw(c1.pin(0), nts::IComponent::InvalidPin);
    cr_assert_throw(c1.pin(6), nts::IComponent::InvalidPin);
}
