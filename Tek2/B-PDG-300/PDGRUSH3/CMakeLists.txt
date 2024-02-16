cmake_minimum_required(VERSION 3.22)

project(MyGKrellm,
    VERSION 1.0
    DESCRIPTION "B-PDG-300 Rush3"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

# set(CMAKE_BUILD_TYPE Debug)

# define headers in a variable
set(HEADERS
    include/krell/core/Types.hpp
    include/krell/core/Configuration.hpp
    include/krell/core/Monitor.hpp
    include/krell/core/KernelParser.hpp
    include/krell/displays/IDisplay.hpp
    include/krell/displays/NCursesDisplay.hpp
    include/krell/displays/SFMLDisplay.hpp
    include/krell/modules/IModule.hpp
    include/krell/modules/ModuleFactory.hpp
    include/krell/modules/CpuModule.hpp
    include/krell/modules/RamModule.hpp
    include/krell/modules/SystemInfoModule.hpp
    include/krell/modules/BatteryModule.hpp
)

set(SOURCES
    src/krell/core/Monitor.cpp
    src/krell/core/Configuration.cpp
    src/krell/core/DisplayMode.cpp
    src/krell/core/KernelParser.cpp
    src/krell/displays/NCursesDisplay.cpp
    src/krell/displays/SFMLDisplay.cpp
    src/krell/modules/ModuleFactory.cpp
    src/krell/modules/CpuModule.cpp
    src/krell/modules/RamModule.cpp
    src/krell/modules/SystemInfoModule.cpp
    src/krell/modules/BatteryModule.cpp
    src/main.cpp
)

add_executable(MyGKrellm ${HEADERS} ${SOURCES})
target_include_directories(MyGKrellm PRIVATE include)
target_link_libraries(MyGKrellm PRIVATE ncurses sfml-graphics sfml-window sfml-system)
