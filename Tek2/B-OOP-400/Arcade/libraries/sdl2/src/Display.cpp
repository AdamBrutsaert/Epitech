/*
** EPITECH PROJECT, 2024
** Display.cpp
** File description:
** Display.cpp
*/

#include "Display.hpp"

#include "TextureManager.hpp"
#include "FontManager.hpp"

#include <SDL2/SDL_image.h>

namespace sdl2 {
    Display::Display()
    {
        this->_title = "Arcade";
        this->_framerate = 0;
        this->_tileSize = 16;
        this->_width = 80;
        this->_height = 60;
        this->_opened = true;

        this->_window = SDL_CreateWindow(
            "Arcade",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            this->_width * this->_tileSize, this->_height * this->_tileSize,
            SDL_WINDOW_SHOWN
        );

        if (this->_window != nullptr) {
            this->_renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
            IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);
        }
    }

    Display::~Display()
    {
        if (this->_renderer != nullptr)
            SDL_DestroyRenderer(this->_renderer);
        if (this->_window != nullptr) {
            SDL_DestroyWindow(this->_window);
            IMG_Quit();
        }
    }

    void Display::setTitle(const std::string &title)
    {
        if (this->_window != nullptr)
            SDL_SetWindowTitle(this->_window, title.c_str());
        this->_title = title;
    }

    void Display::setFramerate(unsigned int framerate)
    {
        this->_framerate = framerate;
    }

    void Display::setTileSize(std::size_t size)
    {
        this->_tileSize = size;
        this->_resizeWindow();
    }

    void Display::setWidth(std::size_t width)
    {
        this->_width = width;
        this->_resizeWindow();
    }

    void Display::setHeight(std::size_t height)
    {
        this->_height = height;
        this->_resizeWindow();
    }

    void Display::_resizeWindow()
    {
        if (this->_window != nullptr)
            SDL_SetWindowSize(this->_window, this->_width * this->_tileSize, this->_height * this->_tileSize);
    }

    bool Display::opened() const
    {
        if (this->_window == nullptr)
            return false;
        return this->_opened;
    }

    void Display::close()
    {
        this->_opened = false;
    }

    static arc::KeyCode MapSDL2Key(SDL_Keycode key)
    {
        if (key >= 'a' && key <= 'z') return static_cast<arc::KeyCode>(key - 'a');
        if (key == SDLK_UP) return arc::KeyCode::UP;
        if (key == SDLK_DOWN) return arc::KeyCode::DOWN;
        if (key == SDLK_LEFT) return arc::KeyCode::LEFT;
        if (key == SDLK_RIGHT) return arc::KeyCode::RIGHT;
        if (key == SDLK_SPACE) return arc::KeyCode::SPACE;
        if (key == SDLK_RETURN) return arc::KeyCode::ENTER;
        if (key == SDLK_ESCAPE) return arc::KeyCode::ESCAPE;
        if (key == SDLK_BACKSPACE || key == SDLK_DELETE) return arc::KeyCode::DELETE;
        if (key == SDLK_TAB) return arc::KeyCode::TAB;
        return arc::KeyCode::UNKNOWN;
    }

    arc::MouseButton MapSDL2MouseButton(Uint8 button)
    {
        if (button == SDL_BUTTON_LEFT) return arc::MouseButton::LEFT;
        if (button == SDL_BUTTON_MIDDLE) return arc::MouseButton::MIDDLE;
        if (button == SDL_BUTTON_RIGHT) return arc::MouseButton::RIGHT;
        return arc::MouseButton::UNKNOWN;
    }

    void Display::update([[maybe_unused]] float deltaTime)
    {
        SDL_Event e;

        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_QUIT:
                this->_opened = false;
                break;
            case SDL_KEYDOWN:
                this->_events.push_back(arc::Event{
                    .type = arc::EventType::KEY_PRESSED,
                    .key = {
                        .code = MapSDL2Key(e.key.keysym.sym),
                        .shift = (bool)(e.key.keysym.mod & KMOD_SHIFT)
                    }
                });
                break;
            case SDL_MOUSEBUTTONDOWN:
                this->_events.push_back(arc::Event{
                    .type = arc::EventType::MOUSE_BUTTON_PRESSED,
                    .mouse = {
                        .button = MapSDL2MouseButton(e.button.button),
                        .x = e.button.x,
                        .y = e.button.y
                    }
                });
                break;
            default:
                break;
            }
        }

        if (_framerate == 0)
            return;

        float sleeping = std::max(0.0, (1.0 / this->_framerate - deltaTime) * 1000.0);
        SDL_Delay(sleeping);
    }

    bool Display::pollEvent(arc::Event &event)
    {
        if (this->_events.empty())
            return false;

        event = this->_events.front();
        this->_events.pop_front();
        return true;
    }

    void Display::clear(arc::Color color)
    {
        if (this->_renderer != nullptr) {
            SDL_SetRenderDrawColor(this->_renderer, color.red, color.green, color.blue, color.alpha);
            SDL_RenderClear(this->_renderer);
        }
    }

    void Display::draw(std::shared_ptr<arc::ITexture> texture, float x, float y)
    {
        if (this->_renderer == nullptr || texture == nullptr)
            return;

        auto sdlTexture = std::dynamic_pointer_cast<Texture>(texture);
        SDL_Rect src = sdlTexture->rect();
        SDL_Rect dest = {
            .x = static_cast<int>(x * this->_tileSize),
            .y = static_cast<int>(y * this->_tileSize),
            .w = static_cast<int>(this->_tileSize),
            .h = static_cast<int>(this->_tileSize)
        };

        if (sdlTexture->texture() != nullptr)
            SDL_RenderCopy(this->_renderer, sdlTexture->texture(), &src, &dest);
    }

    void Display::print(const std::string &string, std::shared_ptr<arc::IFont> font, float x, float y)
    {
        if (this->_renderer == nullptr || font == nullptr)
            return;

        auto sdlFont = std::dynamic_pointer_cast<Font>(font);
        if (sdlFont->font() == nullptr)
            return;

        SDL_Surface* surface = TTF_RenderText_Blended(sdlFont->font(), string.c_str(), sdlFont->color());
        if (surface == nullptr)
            return;

        SDL_Texture* texture = SDL_CreateTextureFromSurface(this->_renderer, surface);
        if (texture == nullptr) {
            SDL_FreeSurface(surface);
            return;
        }

        SDL_Rect dest = {
            .x = static_cast<int>(x * this->_tileSize),
            .y = static_cast<int>(y * this->_tileSize),
            .w = surface->w,
            .h = surface->h
        };

        SDL_RenderCopy(this->_renderer, texture, nullptr, &dest);
        SDL_DestroyTexture(texture);
        SDL_FreeSurface(surface);
    }

    arc::FRect Display::measure(const std::string &string, std::shared_ptr<arc::IFont> font, float x, float y)
    {
        if (this->_renderer == nullptr || font == nullptr)
            return arc::FRect{.x= 0, .y = 0, .width = 0, .height = 0};

        auto sdlFont = std::dynamic_pointer_cast<Font>(font);
        if (sdlFont->font() == nullptr)
            return arc::FRect{.x= 0, .y = 0, .width = 0, .height = 0};

        SDL_Surface* surface = TTF_RenderText_Blended(sdlFont->font(), string.c_str(), sdlFont->color());
        if (surface == nullptr)
            return arc::FRect{.x= 0, .y = 0, .width = 0, .height = 0};

        auto rect = arc::FRect{
            .x = x,
            .y = y,
            .width = (float)(surface->w) / this->_tileSize,
            .height = (float)(surface->h) / this->_tileSize
        };

        SDL_FreeSurface(surface);
        return rect;
    }

    void Display::flush()
    {
        if (this->_renderer != nullptr)
            SDL_RenderPresent(this->_renderer);
    }
}
