/*
** EPITECH PROJECT, 2024
** SDL2TextureManager.hpp
** File description:
** SDL2TextureManager.hpp
*/

#pragma once

#include "arcade/ITextureManager.hpp"
#include "Display.hpp"

#include <vector>

namespace sdl2 {
    class Texture : public arc::ITexture {
    public:
        Texture() = default;
        virtual ~Texture() = default;

        void load(const arc::TextureSpecification& spec, SDL_Texture *texture, std::optional<arc::URect> rect);
        inline virtual const arc::TextureSpecification& specification() const { return this->_spec; }

        inline SDL_Texture* texture() const { return this->_texture; }
        inline SDL_Rect rect() const { return this->_rect; }

    private:
        arc::TextureSpecification _spec;
        SDL_Texture* _texture;
        SDL_Rect _rect;
    };

    class TextureManager : public arc::ITextureManager {
    public:
        TextureManager(Display& display);
        virtual ~TextureManager();

        virtual bool load(const std::string& name, const arc::TextureSpecification& spec);
        virtual std::shared_ptr<arc::ITexture> get(const std::string& name);
        virtual std::map<std::string, arc::TextureSpecification> dump() const;

    private:
        Display& _display;
        std::vector<SDL_Texture*> _coloredTextures;
        std::map<std::string, SDL_Texture*> _cache;
        std::map<std::string, std::shared_ptr<Texture>> _textures;
    };
}
