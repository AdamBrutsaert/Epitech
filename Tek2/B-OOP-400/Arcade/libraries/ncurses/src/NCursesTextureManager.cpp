/*
** EPITECH PROJECT, 2024
** NCursesTextureManager.cpp
** File description:
** NCursesTextureManager.cpp
*/

#include "NCursesTextureManager.hpp"

void NCursesTexture::load(const arc::TextureSpecification& spec)
{
    this->_spec = spec;
}

bool NCursesTextureManager::load(const std::string& name, const arc::TextureSpecification& spec)
{
    auto texture = std::make_shared<NCursesTexture>();

    texture->load(spec);
    this->_textures[name] = texture;
    return true;
}

std::shared_ptr<arc::ITexture> NCursesTextureManager::get(const std::string& name)
{
    if (this->_textures.find(name) == this->_textures.end())
        return nullptr;
    return this->_textures[name];
}

std::map<std::string, arc::TextureSpecification> NCursesTextureManager::dump() const
{
    auto specs = std::map<std::string, arc::TextureSpecification>{};

    for (const auto& [name, texture] : this->_textures)
        specs[name] = texture->specification();

    return specs;
}
