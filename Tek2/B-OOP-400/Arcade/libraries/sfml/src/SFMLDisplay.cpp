/*
** EPITECH PROJECT, 2024
** SFMLDisplay.cpp
** File description:
** SFMLDisplay.cpp
*/

#include "SFMLDisplay.hpp"
#include "SFMLTextureManager.hpp"
#include "SFMLFontManager.hpp"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

SFMLDisplay::SFMLDisplay()
{
    this->_tileSize = 16;
    this->_width = 80;
    this->_height = 60;
    this->_framerate = 0;
    this->_title = "Arcade";

    sf::VideoMode mode;
    mode.width = this->_width * this->_tileSize;
    mode.height = this->_height * this->_tileSize;
    mode.bitsPerPixel = 32;
    this->_window.create(mode, this->_title, sf::Style::Titlebar | sf::Style::Close);
    // this->_window.setKeyRepeatEnabled(false);
}

void SFMLDisplay::setTitle(const std::string& title)
{
    this->_title = title;
    this->_window.setTitle(title);
}

void SFMLDisplay::setFramerate(uint32_t framerate)
{
    this->_framerate = framerate;
    this->_window.setFramerateLimit(framerate);
}

void SFMLDisplay::setTileSize(std::size_t size)
{
    this->_tileSize = size;
    this->_resizeWindow();
}

void SFMLDisplay::setWidth(std::size_t width)
{
    this->_width = width;
    this->_resizeWindow();
}

void SFMLDisplay::setHeight(std::size_t height)
{
    this->_height = height;
    this->_resizeWindow();
}

void SFMLDisplay::_resizeWindow()
{
    sf::Vector2u size;
    size.x = this->_width * this->_tileSize;
    size.y = this->_height * this->_tileSize;

    this->_window.setSize(size);
    this->_window.setView(sf::View(sf::FloatRect(0, 0, size.x, size.y)));
}

static arc::KeyCode MapSFMLKey(sf::Keyboard::Key key)
{
    if (key < 26) return static_cast<arc::KeyCode>(key);
    if (key == sf::Keyboard::Up) return arc::KeyCode::UP;
    if (key == sf::Keyboard::Down) return arc::KeyCode::DOWN;
    if (key == sf::Keyboard::Left) return arc::KeyCode::LEFT;
    if (key == sf::Keyboard::Right) return arc::KeyCode::RIGHT;
    if (key == sf::Keyboard::Space) return arc::KeyCode::SPACE;
    if (key == sf::Keyboard::Enter) return arc::KeyCode::ENTER;
    if (key == sf::Keyboard::Escape) return arc::KeyCode::ESCAPE;
    if (key == sf::Keyboard::Delete || key == sf::Keyboard::Backspace) return arc::KeyCode::DELETE;
    if (key == sf::Keyboard::Tab) return arc::KeyCode::TAB;
    return arc::KeyCode::UNKNOWN;
}

static arc::MouseButton MapSFMLMouseButton(sf::Mouse::Button button)
{
    if (button == sf::Mouse::Left) return arc::MouseButton::LEFT;
    if (button == sf::Mouse::Right) return arc::MouseButton::RIGHT;
    if (button == sf::Mouse::Middle) return arc::MouseButton::MIDDLE;
    return arc::MouseButton::UNKNOWN;
}

void SFMLDisplay::update([[maybe_unused]] float deltaTime)
{
    sf::Event event;
    arc::Event e;

    while (this->_window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            this->_window.close();
            break;
        case sf::Event::KeyPressed:
            e.type = arc::EventType::KEY_PRESSED;
            e.key.code = MapSFMLKey(event.key.code);
            e.key.shift = event.key.shift;
            this->_events.push_back(std::move(e));
            break;
        case sf::Event::MouseButtonPressed:
            e.type = arc::EventType::MOUSE_BUTTON_PRESSED;
            e.mouse.button = MapSFMLMouseButton(event.mouseButton.button);
            e.mouse.x = event.mouseButton.x / this->_tileSize;
            e.mouse.y = event.mouseButton.y / this->_tileSize;
            this->_events.push_back(std::move(e));
            break;
        default:
            break;
        }
    }
}

bool SFMLDisplay::pollEvent(arc::Event& event)
{
    if (this->_events.empty())
        return false;

    event = this->_events.front();
    this->_events.pop_front();
    return true;
}

void SFMLDisplay::clear(arc::Color color)
{
    this->_window.clear(sf::Color{color.red, color.green, color.blue, color.alpha});
}

void SFMLDisplay::draw(std::shared_ptr<arc::ITexture> texture, float x, float y)
{
    if (texture == nullptr)
        return;

    auto sfmlTexture = std::dynamic_pointer_cast<SFMLTexture>(texture);
    auto rect = sf::RectangleShape{sf::Vector2f{static_cast<float>(this->_tileSize), static_cast<float>(this->_tileSize)}};
    rect.setTexture(sfmlTexture->raw().get());
    rect.setTextureRect(sfmlTexture->rect());
    rect.setPosition(x * this->_tileSize, y * this->_tileSize);
    this->_window.draw(rect);
}

void SFMLDisplay::print(const std::string& string, std::shared_ptr<arc::IFont> font, float x, float y)
{
    if (font == nullptr)
        return;

    auto sfmlFont = std::dynamic_pointer_cast<SFMLFont>(font);
    auto text = sf::Text(sf::String(string), sfmlFont->font(), sfmlFont->size());
    text.setFillColor(sfmlFont->color());
    text.setPosition(x * this->_tileSize, y * this->_tileSize);
    this->_window.draw(text);
}

arc::FRect SFMLDisplay::measure(const std::string& string, std::shared_ptr<arc::IFont> font, float x, float y)
{
    if (font == nullptr)
        return {0, 0, 0, 0};

    auto sfmlFont = std::dynamic_pointer_cast<SFMLFont>(font);
    auto text = sf::Text(sf::String(string), sfmlFont->font(), sfmlFont->size());
    text.setPosition(x * this->_tileSize, y * this->_tileSize);
    auto bounds = text.getGlobalBounds();
    return {bounds.left / this->_tileSize, bounds.top / this->_tileSize, bounds.width / this->_tileSize, bounds.height / this->_tileSize};
}

void SFMLDisplay::flush()
{
    this->_window.display();
}
