/*
** EPITECH PROJECT, 2024
** MyCat.cpp
** File description:
** MyCat.cpp
*/

#include <iostream>
#include <fstream>

static bool cat_file(std::string_view filepath)
{
    std::ifstream file(filepath.data());

    if (!file) {
        std::cerr << "MyCat: " << filepath << ": No such file or directory" << std::endl;
        return false;
    }

    std::cout << file.rdbuf();
    return true;
}

static void cat_stdin(void)
{
    std::cout << std::cin.rdbuf();
}

int main(int argc, char **argv)
{
    bool failed = false;

    if (argc == 1) {
        cat_stdin();
    } else {
        for (int i = 1; i < argc; i++) {
            if (!cat_file(argv[i]))
                failed = true;
        }
    }

    return !!failed * 84;
}
