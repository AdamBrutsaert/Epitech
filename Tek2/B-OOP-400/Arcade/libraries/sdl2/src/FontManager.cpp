/*
** EPITECH PROJECT, 2024
** FontManager.cpp
** File description:
** FontManager.cpp
*/

#include "FontManager.hpp"

namespace sdl2 {
    Font::~Font()
    {
        if (this->_font != nullptr)
            TTF_CloseFont(this->_font);
    }

    bool Font::load(const arc::FontSpecification &spec)
    {
        this->_spec = spec;
        this->_font = TTF_OpenFont(spec.path.c_str(), spec.size);
        return this->_font != nullptr;
    }

    FontManager::FontManager()
    {
        TTF_Init();
    }

    FontManager::~FontManager()
    {
        // It crashes for no apparent reason
        // TTF_Quit();
    }

    bool FontManager::load(const std::string &name, const arc::FontSpecification &spec)
    {
        auto font = std::make_shared<Font>();
        if (!font->load(spec))
            return false;
        this->_fonts[name] = font;
        return true;
    }

    std::shared_ptr<arc::IFont> FontManager::get(const std::string &name)
    {
        if (this->_fonts.find(name) == this->_fonts.end())
            return nullptr;
        return this->_fonts[name];
    }

    std::map<std::string, arc::FontSpecification> FontManager::dump() const
    {
        std::map<std::string, arc::FontSpecification> fonts;

        for (auto &font : this->_fonts)
            fonts[font.first] = font.second->specification();

        return fonts;
    }
}
