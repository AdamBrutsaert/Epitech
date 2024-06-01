/*
** EPITECH PROJECT, 2024
** SDL2TextureManager.cpp
** File description:
** SDL2TextureManager.cpp
*/

#include "TextureManager.hpp"

#include <SDL2/SDL_image.h>

namespace sdl2 {
    void Texture::load(const arc::TextureSpecification& spec, SDL_Texture *texture, std::optional<arc::URect> rect)
    {
        this->_spec = spec;
        this->_texture = texture;

        if (rect.has_value()) {
            this->_rect.x = rect.value().x;
            this->_rect.y = rect.value().y;
            this->_rect.w = rect.value().width;
            this->_rect.h = rect.value().height;
        } else {
            this->_rect.x = 0;
            this->_rect.y = 0;
            SDL_QueryTexture(texture, nullptr, nullptr, &this->_rect.w, &this->_rect.h);
        }
    }

    TextureManager::TextureManager(Display& display)
        : _display(display)
    {
    }

    TextureManager::~TextureManager()
    {
        for (auto& texture : this->_cache)
            SDL_DestroyTexture(texture.second);
        for (auto& texture : this->_coloredTextures)
            SDL_DestroyTexture(texture);
    }

    bool TextureManager::load(const std::string& name, const arc::TextureSpecification& spec)
    {
        auto texture = std::make_shared<Texture>();
        SDL_Texture *sdlTexture = nullptr;
        std::optional<arc::URect> rect = std::nullopt;

        if (std::holds_alternative<arc::TextureImage>(spec.graphical)) {
            auto img = std::get<arc::TextureImage>(spec.graphical);
            rect = img.subrect;

            if (this->_cache.find(img.path) != this->_cache.end()) {
                sdlTexture = this->_cache[img.path];
            } else {
                auto imgSurface = IMG_Load(img.path.c_str());
                if (!imgSurface)
                    return false;
                sdlTexture = SDL_CreateTextureFromSurface(this->_display.renderer(), imgSurface);
                if (!sdlTexture) {
                    SDL_FreeSurface(imgSurface);
                    return false;
                }
                SDL_FreeSurface(imgSurface);
                this->_cache[img.path] = sdlTexture;
            }

        } else {
            auto color = std::get<arc::Color>(spec.graphical);

            auto img = SDL_CreateRGBSurface(0, 1, 1, 32, 0, 0, 0, 0);
            if (!img)
                return false;
            SDL_FillRect(img, nullptr, SDL_MapRGB(img->format, color.red, color.green, color.blue));
            sdlTexture = SDL_CreateTextureFromSurface(this->_display.renderer(), img);
            if (!sdlTexture) {
                SDL_FreeSurface(img);
                return false;
            }
            SDL_FreeSurface(img);
            this->_coloredTextures.push_back(sdlTexture);
        }

        texture->load(spec, sdlTexture, rect);
        this->_textures[name] = texture;
        return true;
    }

    std::shared_ptr<arc::ITexture> TextureManager::get(const std::string& name)
    {
        if (this->_textures.find(name) == this->_textures.end())
            return nullptr;
        return this->_textures[name];
    }

    std::map<std::string, arc::TextureSpecification> TextureManager::dump() const
    {
        std::map<std::string, arc::TextureSpecification> specs;

        for (auto& texture : this->_textures)
            specs[texture.first] = texture.second->specification();

        return specs;
    }
}
