##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME := ../../lib/arcade_sdl2.so
SRC  := $(shell find src -name "*.cpp")
OBJ  := $(SRC:src/%.cpp=../../build/obj/sdl2/%.o)
DEP  := $(SRC:src/%.cpp=../../build/dep/sdl2/%.d)

SHARED_SRC := $(shell find ../../shared/src -name "*.cpp")
SHARED_OBJ := $(SHARED_SRC:../../shared/src/%.cpp=../../build/obj/shared/%.o)
SHARED_DEP := $(SHARED_SRC:../../shared/src/%.cpp=../../build/dep/shared/%.d)

CPPFLAGS := -iquote include -iquote ../../shared/include
CXXFLAGS := -std=c++20 -fPIC -fno-gnu-unique -Wall -Wextra -Werror
LDFLAGS  := -shared
LDLIBS   := -lSDL2_mixer -lSDL2_ttf -lSDL2_image -lSDL2

all: $(NAME)

clean:
	@rm -rf build

fclean: clean
	@rm -rf $(NAME)

re:
	@$(MAKE) -s fclean
	@$(MAKE) -s all

.PHONY: all clean fclean re

$(NAME): $(OBJ) $(SHARED_OBJ)
	@mkdir -p $(dir $(NAME))
	@g++ $^ -o $@ $(LDFLAGS) $(LDLIBS)

../../build/obj/sdl2/%.o: src/%.cpp ../../build/dep/sdl2/%.d
	@mkdir -p $(dir $@)
	@mkdir -p $(dir ../../build/dep/sdl2/$*.d)
	@g++ -c $< -o $@ $(CPPFLAGS) $(CXXFLAGS) \
		-MT $@ -MMD -MP -MF ../../build/dep/sdl2/$*.d

../../build/obj/shared/%.o: ../../shared/src/%.cpp ../../build/dep/shared/%.d
	@mkdir -p $(dir $@)
	@mkdir -p $(dir ../../build/dep/shared/$*.d)
	@g++ -c $< -o $@ $(CPPFLAGS) $(CXXFLAGS) \
		-MT $@ -MMD -MP -MF ../../build/dep/shared/$*.d

$(DEP) $(SHARED_DEP):

-include $(DEP)
-include $(SHARED_DEP)
