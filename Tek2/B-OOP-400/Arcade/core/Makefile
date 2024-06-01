##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME := ../arcade
SRC  := $(shell find src -name "*.cpp")
OBJ  := $(SRC:src/%.cpp=../build/obj/core/%.o)
DEP  := $(SRC:src/%.cpp=../build/dep/core/%.d)

SHARED_SRC := $(shell find ../shared/src -name "*.cpp")
SHARED_OBJ := $(SHARED_SRC:../shared/src/%.cpp=../build/obj/shared/%.o)
SHARED_DEP := $(SHARED_SRC:../shared/src/%.cpp=../build/dep/shared/%.d)

CPPFLAGS := -iquote include -iquote ../shared/include
CXXFLAGS := -std=c++20 -fno-gnu-unique -Wall -Wextra -Werror
LDFLAGS  :=
LDLIBS   :=

all: $(NAME)

clean:
	@rm -rf ../build/obj/core
	@rm -rf ../build/dep/core

fclean: clean
	@rm -rf $(NAME)

re:
	@$(MAKE) -s fclean
	@$(MAKE) -s all

.PHONY: all clean fclean re

$(NAME): $(OBJ) $(SHARED_OBJ)
	@g++ $^ -o $@ $(LDFLAGS) $(LDLIBS)

../build/obj/core/%.o: src/%.cpp ../build/dep/core/%.d
	@mkdir -p $(dir $@)
	@mkdir -p $(dir ../build/dep/core/$*.d)
	@g++ -c $< -o $@ $(CPPFLAGS) $(CXXFLAGS) \
		-MT $@ -MMD -MP -MF ../build/dep/core/$*.d

../build/obj/shared/%.o: CXXFLAGS += -fPIC
../build/obj/shared/%.o: ../shared/src/%.cpp ../build/dep/shared/%.d
	@mkdir -p $(dir $@)
	@mkdir -p $(dir ../build/dep/shared/$*.d)
	@g++ -c $< -o $@ $(CPPFLAGS) $(CXXFLAGS) \
		-MT $@ -MMD -MP -MF ../build/dep/shared/$*.d

$(DEP) $(SHARED_DEP):

-include $(DEP)
-include $(SHARED_DEP)
