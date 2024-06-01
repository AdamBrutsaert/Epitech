/*
** EPITECH PROJECT, 2024
** NCursesTextureManager.hpp
** File description:
** NCursesTextureManager.hpp
*/

#pragma once

#include "arcade/ITextureManager.hpp"

#include <map>

class NCursesTexture : public arc::ITexture {
public:
    NCursesTexture() = default;
    virtual ~NCursesTexture() = default;

    void load(const arc::TextureSpecification& spec);
    inline virtual const arc::TextureSpecification& specification() const { return this->_spec; }

private:
    arc::TextureSpecification _spec;
};

class NCursesTextureManager : public arc::ITextureManager {
public:
    NCursesTextureManager() = default;
    virtual ~NCursesTextureManager() = default;

    virtual bool load(const std::string& name, const arc::TextureSpecification& spec);
    virtual std::shared_ptr<arc::ITexture> get(const std::string& name);
    virtual std::map<std::string, arc::TextureSpecification> dump() const;

private:
    std::map<std::string, std::shared_ptr<NCursesTexture>> _textures;
};
