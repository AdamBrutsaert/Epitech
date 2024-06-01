/*
** EPITECH PROJECT, 2024
** NCursesFontManager.hpp
** File description:
** NCursesFontManager.hpp
*/

#pragma once

#include "arcade/IFontManager.hpp"

#include <map>

class NCursesFont : public arc::IFont {
public:
    NCursesFont() = default;
    virtual ~NCursesFont() = default;

    void load(const arc::FontSpecification& spec);
    inline virtual const arc::FontSpecification& specification() const { return this->_spec; }

private:
    arc::FontSpecification _spec;
};

class NCursesFontManager : public arc::IFontManager {
public:
    NCursesFontManager() = default;
    virtual ~NCursesFontManager() = default;

    virtual bool load(const std::string& name, const arc::FontSpecification& spec);
    virtual std::shared_ptr<arc::IFont> get(const std::string& name);
    virtual std::map<std::string, arc::FontSpecification> dump() const;

private:
    std::map<std::string, std::shared_ptr<NCursesFont>> _fonts;
};
