/*
** EPITECH PROJECT, 2024
** NCursesDisplay.hpp
** File description:
** NCursesDisplay.hpp
*/

#pragma once

#include "arcade/IDisplay.hpp"

#include <deque>

class NCursesDisplay : public arc::IDisplay {
public:
    NCursesDisplay();
    virtual ~NCursesDisplay();

    virtual void setTitle(const std::string& title);
    virtual void setFramerate(uint32_t framerate);
    virtual void setTileSize(std::size_t size);
    virtual void setWidth(std::size_t width);
    virtual void setHeight(std::size_t height);

    inline virtual std::string title() const { return this->_title; }
    inline virtual uint32_t framerate() const { return this->_framerate; }
    inline virtual std::size_t tileSize() const { return this->_tileSize; }
    inline virtual std::size_t width() const { return this->_width; }
    inline virtual std::size_t height() const { return this->_height; }

    virtual bool opened() const { return this->_opened; }
    virtual void close() { this->_opened = false; }

    virtual void update(float deltaTime);
    virtual bool pollEvent(arc::Event& event);

    virtual void clear(arc::Color color);
    virtual void draw(std::shared_ptr<arc::ITexture> texture, float x, float y);
    virtual void print(const std::string& string, std::shared_ptr<arc::IFont> font, float x, float y);
    virtual arc::FRect measure(const std::string& string, std::shared_ptr<arc::IFont> font, float x, float y);
    virtual void flush();

private:
    void _resizeWindow();

private:
    bool _opened;
    bool _colored;

    // Specification
    std::string _title;
    uint32_t _framerate;
    std::size_t _width;
    std::size_t _height;
    std::size_t _tileSize;

    // Events
    std::deque<arc::Event> _events;
};
