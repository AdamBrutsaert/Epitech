/*
** EPITECH PROJECT, 2024
** NCursesFontManager.cpp
** File description:
** NCursesFontManager.cpp
*/

#include "NCursesFontManager.hpp"

void NCursesFont::load(const arc::FontSpecification& spec)
{
    this->_spec = spec;
}

bool NCursesFontManager::load(const std::string& name, const arc::FontSpecification& spec)
{
    auto font = std::make_shared<NCursesFont>();

    font->load(spec);
    this->_fonts[name] = font;
    return true;
}

std::shared_ptr<arc::IFont> NCursesFontManager::get(const std::string& name)
{
    if (this->_fonts.find(name) == this->_fonts.end())
        return nullptr;
    return this->_fonts[name];
}

std::map<std::string, arc::FontSpecification> NCursesFontManager::dump() const
{
    auto specs = std::map<std::string, arc::FontSpecification>{};

    for (const auto& [name, font] : this->_fonts)
        specs[name] = font->specification();

    return specs;
}
