/*
** EPITECH PROJECT, 2024
** ex06.cpp
** File description:
** ex06.cpp
*/

#include "../ex06/Toy.hpp"
#include "../ex06/ToyStory.hpp"
#include "../ex06/Buzz.hpp"
#include "../ex06/Woody.hpp"

int main()
{
    Buzz b("buzzi");
    Woody w("wood");

    ToyStory::tellMeAStory("story.txt", b, &Toy::speak_es, w, &Toy::speak);
}
