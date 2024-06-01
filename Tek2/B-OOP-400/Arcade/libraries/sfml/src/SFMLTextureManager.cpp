/*
** EPITECH PROJECT, 2024
** SFMLTextureManager.cpp
** File description:
** SFMLTextureManager.cpp
*/

#include "SFMLTextureManager.hpp"

void SFMLTexture::load(
    const arc::TextureSpecification& spec,
    const std::shared_ptr<sf::Texture>& texture,
    std::optional<arc::URect> rect
)
{
    this->_spec = spec;
    this->_texture = texture;

    if (rect.has_value()) {
        this->_rect = sf::IntRect(
            rect.value().x,
            rect.value().y,
            rect.value().width,
            rect.value().height
        );
    } else {
        this->_rect = sf::IntRect(
            0,
            0,
            texture->getSize().x,
            texture->getSize().y
        );
    }
}

bool SFMLTextureManager::load(const std::string& name, const arc::TextureSpecification& spec)
{
    auto texture = std::make_shared<SFMLTexture>();
    std::shared_ptr<sf::Texture> sfmlTexture{};
    std::optional<arc::URect> rect = std::nullopt;

    if (std::holds_alternative<arc::TextureImage>(spec.graphical)) {
        auto image = std::get<arc::TextureImage>(spec.graphical);

        rect = image.subrect;

        if (this->_cache.find(image.path) != this->_cache.end()) {
            sfmlTexture = this->_cache[image.path];
        } else {
            sfmlTexture = std::make_shared<sf::Texture>();
            if (!sfmlTexture->loadFromFile(image.path))
                return false;
            this->_cache[image.path] = sfmlTexture;
        }
    } else {
        auto color = std::get<arc::Color>(spec.graphical);

        auto img = sf::Image{};
        img.create(1, 1, sf::Color(color.red, color.green, color.blue, color.alpha));

        sfmlTexture = std::make_shared<sf::Texture>();
        if (!sfmlTexture->loadFromImage(img))
            return false;
    }

    texture->load(spec, sfmlTexture, rect);
    this->_textures[name] = texture;
    return true;
}

std::shared_ptr<arc::ITexture> SFMLTextureManager::get(const std::string& name)
{
    if (this->_textures.find(name) == this->_textures.end())
        return nullptr;
    return this->_textures[name];
}

std::map<std::string, arc::TextureSpecification> SFMLTextureManager::dump() const
{
    auto specs = std::map<std::string, arc::TextureSpecification>{};

    for (const auto& [name, texture] : this->_textures)
        specs[name] = texture->specification();

    return specs;
}
