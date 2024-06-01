/*
** EPITECH PROJECT, 2024
** Tristate.cpp
** File description:
** Tristate.cpp
*/

#include "nts/components/Tristate.hpp"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(Tristate, print, .init = cr_redirect_stdout)
{
    std::cout << nts::Tristate::Undefined << std::endl;
    std::cout << nts::Tristate::True << std::endl;
    std::cout << nts::Tristate::False << std::endl;
    cr_assert_stdout_eq_str("U\n1\n0\n");
}

Test(Tristate, not)
{
    cr_assert_eq(!nts::Tristate::False, nts::Tristate::True);
    cr_assert_eq(!nts::Tristate::True, nts::Tristate::False);
    cr_assert_eq(!nts::Tristate::Undefined, nts::Tristate::Undefined);
}

Test(Tristate, and)
{
    cr_assert_eq(nts::Tristate::False && nts::Tristate::False, nts::Tristate::False);
    cr_assert_eq(nts::Tristate::False && nts::Tristate::True, nts::Tristate::False);
    cr_assert_eq(nts::Tristate::False && nts::Tristate::Undefined, nts::Tristate::False);

    cr_assert_eq(nts::Tristate::True && nts::Tristate::False, nts::Tristate::False);
    cr_assert_eq(nts::Tristate::True && nts::Tristate::True, nts::Tristate::True);
    cr_assert_eq(nts::Tristate::True && nts::Tristate::Undefined, nts::Tristate::Undefined);

    cr_assert_eq(nts::Tristate::Undefined && nts::Tristate::False, nts::Tristate::False);
    cr_assert_eq(nts::Tristate::Undefined && nts::Tristate::True, nts::Tristate::Undefined);
    cr_assert_eq(nts::Tristate::Undefined && nts::Tristate::Undefined, nts::Tristate::Undefined);
}

Test(Tristate, or)
{
    cr_assert_eq(nts::Tristate::False || nts::Tristate::False, nts::Tristate::False);
    cr_assert_eq(nts::Tristate::False || nts::Tristate::True, nts::Tristate::True);
    cr_assert_eq(nts::Tristate::False || nts::Tristate::Undefined, nts::Tristate::Undefined);

    cr_assert_eq(nts::Tristate::True || nts::Tristate::False, nts::Tristate::True);
    cr_assert_eq(nts::Tristate::True || nts::Tristate::True, nts::Tristate::True);
    cr_assert_eq(nts::Tristate::True || nts::Tristate::Undefined, nts::Tristate::True);

    cr_assert_eq(nts::Tristate::Undefined || nts::Tristate::False, nts::Tristate::Undefined);
    cr_assert_eq(nts::Tristate::Undefined || nts::Tristate::True, nts::Tristate::True);
    cr_assert_eq(nts::Tristate::Undefined || nts::Tristate::Undefined, nts::Tristate::Undefined);
}

Test(Tristate, xor)
{
    cr_assert_eq(nts::Tristate::False ^ nts::Tristate::False, nts::Tristate::False);
    cr_assert_eq(nts::Tristate::False ^ nts::Tristate::True, nts::Tristate::True);
    cr_assert_eq(nts::Tristate::False ^ nts::Tristate::Undefined, nts::Tristate::Undefined);

    cr_assert_eq(nts::Tristate::True ^ nts::Tristate::False, nts::Tristate::True);
    cr_assert_eq(nts::Tristate::True ^ nts::Tristate::True, nts::Tristate::False);
    cr_assert_eq(nts::Tristate::True ^ nts::Tristate::Undefined, nts::Tristate::Undefined);

    cr_assert_eq(nts::Tristate::Undefined ^ nts::Tristate::False, nts::Tristate::Undefined);
    cr_assert_eq(nts::Tristate::Undefined ^ nts::Tristate::True, nts::Tristate::Undefined);
    cr_assert_eq(nts::Tristate::Undefined ^ nts::Tristate::Undefined, nts::Tristate::Undefined);
}
