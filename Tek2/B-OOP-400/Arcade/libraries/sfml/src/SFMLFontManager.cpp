/*
** EPITECH PROJECT, 2024
** SFMLFontManager.cpp
** File description:
** SFMLFontManager.cpp
*/

#include "SFMLFontManager.hpp"

bool SFMLFont::load(const arc::FontSpecification& spec)
{
    this->_spec = spec;

    if (!this->_font.loadFromFile(spec.path))
        return false;

    return true;
}

bool SFMLFontManager::load(const std::string& name, const arc::FontSpecification& spec)
{
    auto font = std::make_shared<SFMLFont>();

    if (!font->load(spec))
        return false;
    this->_fonts[name] = font;
    return true;
}

std::shared_ptr<arc::IFont> SFMLFontManager::get(const std::string& name)
{
    if (this->_fonts.find(name) == this->_fonts.end())
        return nullptr;
    return this->_fonts[name];
}

std::map<std::string, arc::FontSpecification> SFMLFontManager::dump() const
{
    auto specs = std::map<std::string, arc::FontSpecification>{};

    for (const auto& [name, font] : this->_fonts)
        specs[name] = font->specification();

    return specs;
}
