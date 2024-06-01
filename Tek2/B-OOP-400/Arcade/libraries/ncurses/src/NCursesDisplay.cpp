/*
** EPITECH PROJECT, 2024
** NCursesDisplay.cpp
** File description:
** NCursesDisplay.cpp
*/

#include "NCursesDisplay.hpp"

#include <ncurses.h>
#include <thread>

static std::map<std::tuple<uint8_t, uint8_t, uint8_t>, int> ColorPairMap = {
    {{0, 0, 0}, 1},
    {{255, 0, 0}, 2},
    {{0, 255, 0}, 3},
    {{255, 255, 0}, 4},
    {{0, 0, 255}, 5},
    {{255, 0, 255}, 6},
    {{0, 255, 255}, 7},
    {{255, 255, 255}, 8}
};

static int GetColorPair(arc::Color color)
{
    auto red = (color.red >= 128) * 255;
    auto green = (color.green >= 128) * 255;
    auto blue = (color.blue >= 128) * 255;
    return ColorPairMap[{red, green, blue}];
}

NCursesDisplay::NCursesDisplay()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    set_escdelay(0);
    mousemask(BUTTON1_PRESSED | BUTTON2_PRESSED | BUTTON3_PRESSED, NULL);
    curs_set(0);
    start_color();

    init_color(COLOR_BLACK, 0, 0, 0);
    init_color(COLOR_RED, 1000, 0, 0);
    init_color(COLOR_GREEN, 0, 1000, 0);
    init_color(COLOR_YELLOW, 1000, 1000, 0);
    init_color(COLOR_BLUE, 0, 0, 1000);
    init_color(COLOR_MAGENTA, 1000, 0, 1000);
    init_color(COLOR_CYAN, 0, 1000, 1000);
    init_color(COLOR_WHITE, 1000, 1000, 1000);

    init_pair(1, COLOR_BLACK, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_CYAN, COLOR_BLACK);
    init_pair(8, COLOR_WHITE, COLOR_BLACK);

    this->_colored = can_change_color();
    this->_opened = true;
    this->_title = "Arcade";
    this->_framerate = 0;
    this->_width = 0;
    this->_height = 0;
    this->_tileSize = 0;
}

NCursesDisplay::~NCursesDisplay()
{
    endwin();
}

void NCursesDisplay::setTitle(const std::string& title)
{
    this->_title = title;
}

void NCursesDisplay::setFramerate(uint32_t framerate)
{
    this->_framerate = framerate;
}

void NCursesDisplay::setTileSize(std::size_t size)
{
    this->_tileSize = size;
}

void NCursesDisplay::setWidth(std::size_t width)
{
    this->_width = width;
}

void NCursesDisplay::setHeight(std::size_t height)
{
    this->_height = height;
}

static arc::KeyCode MapNCursesKey(int key)
{
    if (key >= 'a' && key <= 'z') return static_cast<arc::KeyCode>(key - 'a');
    if (key >= 'A' && key <= 'Z') return static_cast<arc::KeyCode>(key - 'A');
    if (key == ' ') return arc::KeyCode::SPACE;
    if (key == KEY_UP) return arc::KeyCode::UP;
    if (key == KEY_DOWN) return arc::KeyCode::DOWN;
    if (key == KEY_LEFT) return arc::KeyCode::LEFT;
    if (key == KEY_RIGHT) return arc::KeyCode::RIGHT;
    if (key == KEY_ENTER || key == '\n') return arc::KeyCode::ENTER;
    if (key == KEY_BACKSPACE || key == KEY_DC || key == 127) return arc::KeyCode::DELETE;
    if (key == KEY_STAB || key == '\t') return arc::KeyCode::TAB;
    if (key == 27) return arc::KeyCode::ESCAPE;
    return arc::KeyCode::UNKNOWN;
}

static arc::MouseButton MapNCursesMouseButton(MEVENT event)
{
    if (event.bstate & BUTTON1_PRESSED) return arc::MouseButton::LEFT;
    if (event.bstate & BUTTON2_PRESSED) return arc::MouseButton::MIDDLE;
    if (event.bstate & BUTTON3_PRESSED) return arc::MouseButton::RIGHT;
    return arc::MouseButton::UNKNOWN;
}

void NCursesDisplay::update(float deltaTime)
{
    int ch = getch();

    if (ch != ERR) {
        if (ch == KEY_MOUSE) {
            MEVENT event;
            if (getmouse(&event) == OK) {
                arc::Event e;
                e.type = arc::EventType::MOUSE_BUTTON_PRESSED;
                e.mouse.button = MapNCursesMouseButton(event);
                e.mouse.x = event.x;
                e.mouse.y = event.y;
                this->_events.push_back(std::move(e));
            }
        } else {
            arc::KeyCode key = MapNCursesKey(ch);
            arc::Event e;
            e.type = arc::EventType::KEY_PRESSED;
            e.key.code = key;
            e.key.shift = key >= arc::KeyCode::A && key <= arc::KeyCode::Z;
            this->_events.push_back(std::move(e));
        }
    }

    if (_framerate == 0)
        return;

    float sleeping = std::max(0.0, (1.0 / this->_framerate - deltaTime) * 1000.0);
    std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(sleeping)));
}

bool NCursesDisplay::pollEvent(arc::Event& event)
{
    if (this->_events.empty())
        return false;

    event = this->_events.front();
    this->_events.pop_front();
    return true;
}

void NCursesDisplay::clear([[maybe_unused]] arc::Color color)
{
    ::clear();
}

void NCursesDisplay::draw(std::shared_ptr<arc::ITexture> texture, float x, float y)
{
    if (texture == nullptr)
        return;

    auto& spec = texture->specification().textual;

    if (this->_colored) attron(COLOR_PAIR(GetColorPair(spec.color)));
    mvprintw(y, x, "%c", spec.character);
    if (this->_colored) attroff(COLOR_PAIR(GetColorPair(spec.color)));
}

void NCursesDisplay::print(
    const std::string& string,
    std::shared_ptr<arc::IFont> font,
    float x,
    float y
)
{
    if (font == nullptr)
        return;

    auto& spec = font->specification();

    if (this->_colored) attron(COLOR_PAIR(GetColorPair(spec.color)));
    mvprintw(y, x, "%s", string.c_str());
    if (this->_colored) attroff(COLOR_PAIR(GetColorPair(spec.color)));
}

arc::FRect NCursesDisplay::measure(
    const std::string& string,
    [[maybe_unused]] std::shared_ptr<arc::IFont> font,
    float x,
    float y
)
{
    return arc::FRect{x, y, (float)string.length(), 1};
}

void NCursesDisplay::flush()
{
    refresh();
}
