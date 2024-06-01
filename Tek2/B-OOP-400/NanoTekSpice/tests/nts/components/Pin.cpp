/*
** EPITECH PROJECT, 2024
** Pin.cpp
** File description:
** Pin.cpp
*/

#include "nts/components/Pin.hpp"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Pin, constructor)
{
    {
        nts::Pin pin(nts::Pin::Type::Input);

        cr_assert_eq(pin.state(), nts::Tristate::Undefined);
        cr_assert_eq(pin.type(), nts::Pin::Type::Input);
    }

    {
        nts::Pin pin(nts::Pin::Type::Output);

        cr_assert_eq(pin.state(), nts::Tristate::Undefined);
        cr_assert_eq(pin.type(), nts::Pin::Type::Output);
    }
}

Test(Pin, set)
{
    {
        nts::Pin pin(nts::Pin::Type::Output);
        cr_assert_eq(pin.state(), nts::Tristate::Undefined);

        pin.set(nts::Tristate::True);
        cr_assert_eq(pin.state(), nts::Tristate::True);

        pin.set(nts::Tristate::False);
        cr_assert_eq(pin.state(), nts::Tristate::False);

        pin.set(nts::Tristate::Undefined);
        cr_assert_eq(pin.state(), nts::Tristate::Undefined);
    }

    {
        nts::Pin pin(nts::Pin::Type::Input);
        cr_assert_eq(pin.state(), nts::Tristate::Undefined);

        pin.set(nts::Tristate::True);
        cr_assert_eq(pin.state(), nts::Tristate::True);

        pin.set(nts::Tristate::False);
        cr_assert_eq(pin.state(), nts::Tristate::False);

        pin.set(nts::Tristate::Undefined);
        cr_assert_eq(pin.state(), nts::Tristate::Undefined);
    }
}

Test(Pin, link)
{
    nts::Pin output(nts::Pin::Type::Output);
    nts::Pin input(nts::Pin::Type::Input);

    input.link(output);

    cr_assert_eq(input.state(), nts::Tristate::Undefined);
    cr_assert_eq(output.state(), nts::Tristate::Undefined);

    output.set(nts::Tristate::Undefined);
    cr_assert_eq(input.state(), nts::Tristate::Undefined);
    cr_assert_eq(output.state(), nts::Tristate::Undefined);

    output.set(nts::Tristate::True);
    cr_assert_eq(input.state(), nts::Tristate::True);
    cr_assert_eq(output.state(), nts::Tristate::True);

    output.set(nts::Tristate::False);
    cr_assert_eq(input.state(), nts::Tristate::False);
    cr_assert_eq(output.state(), nts::Tristate::False);
}

Test(Pin, bind)
{
    nts::Pin input1(nts::Pin::Type::Input);
    nts::Pin input2(nts::Pin::Type::Input);
    nts::Pin output(nts::Pin::Type::Output);

    input1.bind([&]() {
        output.set(input1.state() && input2.state());
    });

    input2.bind([&]() {
        output.set(input1.state() && input2.state());
    });

    cr_assert_eq(input1.state(), nts::Tristate::Undefined);
    cr_assert_eq(input2.state(), nts::Tristate::Undefined);
    cr_assert_eq(output.state(), nts::Tristate::Undefined);

    input1.set(nts::Tristate::False);
    input2.set(nts::Tristate::False);
    cr_assert_eq(output.state(), nts::Tristate::False);

    input1.set(nts::Tristate::False);
    input2.set(nts::Tristate::True);
    cr_assert_eq(output.state(), nts::Tristate::False);

    input1.set(nts::Tristate::False);
    input2.set(nts::Tristate::Undefined);
    cr_assert_eq(output.state(), nts::Tristate::False);

    input1.set(nts::Tristate::True);
    input2.set(nts::Tristate::False);
    cr_assert_eq(output.state(), nts::Tristate::False);

    input1.set(nts::Tristate::True);
    input2.set(nts::Tristate::True);
    cr_assert_eq(output.state(), nts::Tristate::True);

    input1.set(nts::Tristate::True);
    input2.set(nts::Tristate::Undefined);
    cr_assert_eq(output.state(), nts::Tristate::Undefined);

    input1.set(nts::Tristate::Undefined);
    input2.set(nts::Tristate::False);
    cr_assert_eq(output.state(), nts::Tristate::False);

    input1.set(nts::Tristate::Undefined);
    input2.set(nts::Tristate::True);
    cr_assert_eq(output.state(), nts::Tristate::Undefined);

    input1.set(nts::Tristate::Undefined);
    input2.set(nts::Tristate::Undefined);
    cr_assert_eq(output.state(), nts::Tristate::Undefined);
}
