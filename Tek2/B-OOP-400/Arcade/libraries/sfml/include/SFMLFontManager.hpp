/*
** EPITECH PROJECT, 2024
** SFMLFontManager.hpp
** File description:
** SFMLFontManager.hpp
*/

#pragma once

#include "arcade/IFontManager.hpp"

#include <SFML/Graphics/Font.hpp>

class SFMLFont : public arc::IFont {
public:
    SFMLFont() = default;
    virtual ~SFMLFont() = default;

    bool load(const arc::FontSpecification& spec);

    inline virtual const arc::FontSpecification& specification() const { return this->_spec; }
    inline const sf::Font& font() const { return this->_font; }
    inline std::size_t size() const { return this->_spec.size; }
    inline sf::Color color() const { return sf::Color(this->_spec.color.red, this->_spec.color.green, this->_spec.color.blue, this->_spec.color.alpha); }

private:
    sf::Font _font;
    arc::FontSpecification _spec;
};

class SFMLFontManager : public arc::IFontManager {
public:
    SFMLFontManager() = default;
    virtual ~SFMLFontManager() = default;

    virtual bool load(const std::string& name, const arc::FontSpecification& spec);
    virtual std::shared_ptr<arc::IFont> get(const std::string& name);
    virtual std::map<std::string, arc::FontSpecification> dump() const;

private:
    std::map<std::string, std::shared_ptr<SFMLFont>> _fonts;
};
