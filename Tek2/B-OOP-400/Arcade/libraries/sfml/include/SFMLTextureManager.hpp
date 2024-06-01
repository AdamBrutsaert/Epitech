/*
** EPITECH PROJECT, 2024
** SFMLTextureManager.hpp
** File description:
** SFMLTextureManager.hpp
*/

#pragma once

#include "arcade/ITextureManager.hpp"

#include <SFML/Graphics/Texture.hpp>

#include <memory>
#include <map>

class SFMLTexture : public arc::ITexture {
public:
    SFMLTexture() = default;
    virtual ~SFMLTexture() = default;

    void load(
        const arc::TextureSpecification& spec,
        const std::shared_ptr<sf::Texture>& texture,
        std::optional<arc::URect> rect
    );

    inline virtual const arc::TextureSpecification& specification() const { return this->_spec; }
    inline const std::shared_ptr<sf::Texture>& raw() const { return this->_texture; }
    inline const sf::IntRect& rect() const { return this->_rect; }

private:
    std::shared_ptr<sf::Texture> _texture;
    sf::IntRect _rect;
    arc::TextureSpecification _spec;
};

class SFMLTextureManager : public arc::ITextureManager {
public:
    SFMLTextureManager() = default;
    virtual ~SFMLTextureManager() = default;

    virtual bool load(const std::string& name, const arc::TextureSpecification& spec);
    virtual std::shared_ptr<arc::ITexture> get(const std::string& name);
    virtual std::map<std::string, arc::TextureSpecification> dump() const;

private:
    std::map<std::string, std::shared_ptr<sf::Texture>> _cache;
    std::map<std::string, std::shared_ptr<SFMLTexture>> _textures;
};
