##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME := ../../lib/arcade_ncurses.so
SRC  := $(shell find src -name "*.cpp")
OBJ  := $(SRC:src/%.cpp=../../build/obj/ncurses/%.o)
DEP  := $(SRC:src/%.cpp=../../build/dep/ncurses/%.d)

SHARED_SRC := $(shell find ../../shared/src -name "*.cpp")
SHARED_OBJ := $(SHARED_SRC:../../shared/src/%.cpp=../../build/obj/shared/%.o)
SHARED_DEP := $(SHARED_SRC:../../shared/src/%.cpp=../../build/dep/shared/%.d)

CPPFLAGS := -iquote include -iquote ../../shared/include
CXXFLAGS := -std=c++20 -fPIC -fno-gnu-unique -Wall -Wextra -Werror
LDFLAGS  := -shared
LDLIBS   := -lncurses

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

../../build/obj/ncurses/%.o: src/%.cpp ../../build/dep/ncurses/%.d
	@mkdir -p $(dir $@)
	@mkdir -p $(dir ../../build/dep/ncurses/$*.d)
	@g++ -c $< -o $@ $(CPPFLAGS) $(CXXFLAGS) \
		-MT $@ -MMD -MP -MF ../../build/dep/ncurses/$*.d

../../build/obj/shared/%.o: ../../shared/src/%.cpp ../../build/dep/shared/%.d
	@mkdir -p $(dir $@)
	@mkdir -p $(dir ../../build/dep/shared/$*.d)
	@g++ -c $< -o $@ $(CPPFLAGS) $(CXXFLAGS) \
		-MT $@ -MMD -MP -MF ../../build/dep/shared/$*.d

$(DEP) $(SHARED_DEP):

-include $(DEP)
-include $(SHARED_DEP)
