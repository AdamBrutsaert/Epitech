/*
** EPITECH PROJECT, 2024
** SDL2FontManager.hpp
** File description:
** SDL2FontManager.hpp
*/

#pragma once

#include "arcade/IFontManager.hpp"

#include <SDL2/SDL_ttf.h>

namespace sdl2 {
    class Font : public arc::IFont {
    public:
        Font() = default;
        virtual ~Font();

        bool load(const arc::FontSpecification& spec);
        inline virtual const arc::FontSpecification& specification() const { return this->_spec; }

        inline TTF_Font* font() const { return this->_font; }
        inline SDL_Colour color() const { return { this->_spec.color.red, this->_spec.color.green, this->_spec.color.blue, this->_spec.color.alpha }; }

    private:
        arc::FontSpecification _spec;
        TTF_Font* _font;
    };

    class FontManager : public arc::IFontManager {
    public:
        FontManager();
        virtual ~FontManager();

        virtual bool load(const std::string& name, const arc::FontSpecification& spec);
        virtual std::shared_ptr<arc::IFont> get(const std::string& name);
        virtual std::map<std::string, arc::FontSpecification> dump() const;

    private:
        std::map<std::string, std::shared_ptr<arc::IFont>> _fonts;
    };
}
