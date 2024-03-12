##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

# Library
LIB_NAME      := libasm.so
LIB_SRC       := $(shell find src -name "*.asm")
LIB_NASMFLAGS := -f elf64
LIB_LDFLAGS   := -m elf_x86_64 -shared

# Tests
TESTS_NAME    := unit_tests
TESTS_SRC     := $(shell find tests -name "*.c")
TESTS_CFLAGS  := -std=c17 -Wall -Wextra -fno-builtin

# Intermediate files
LIB_DEBUG_NAME  := $(LIB_NAME:%.so=%-debug.so)
LIB_RELEASE_OBJ := $(LIB_SRC:src/%.asm=build/release/%.o)
LIB_DEBUG_OBJ   := $(LIB_SRC:src/%.asm=build/debug/%.o)
TESTS_OBJ       := $(TESTS_SRC:tests/%.c=build/tests/%.o)

all: lib tests

lib: $(LIB_NAME)

tests: $(TESTS_NAME)

tests_run: tests
	@LD_PRELOAD=./$(LIB_DEBUG_NAME) ./$(TESTS_NAME) > tests/.o1
	@./$(TESTS_NAME) > tests/.o2
	@diff tests/.o1 tests/.o2 && echo "OK" || echo "KO"
	@rm -f tests/.o1 tests/.o2

clean:
	@rm -rf build

fclean: clean
	@rm -f $(LIB_NAME)
	@rm -f $(LIB_DEBUG_NAME)
	@rm -f $(TESTS_NAME)

re:
	@$(MAKE) -s fclean
	@$(MAKE) -s all

.PHONY: all lib tests tests_run clean fclean re

$(LIB_NAME): $(LIB_RELEASE_OBJ)
	@ld $^ -o $@ $(LIB_LDFLAGS) $(LIB_LDLIBS)

$(LIB_DEBUG_NAME): $(LIB_DEBUG_OBJ)
	@ld $^ -o $@ $(LIB_LDFLAGS) $(LIB_LDLIBS)

$(TESTS_NAME): $(LIB_DEBUG_NAME) $(TESTS_OBJ)
	@gcc $(TESTS_OBJ) -o $@ $(TESTS_LDFLAGS) $(TESTS_LDLIBS)

build/release/%.o: src/%.asm
	@mkdir -p $(dir $@)
	@nasm $< -o $@ $(LIB_NASMFLAGS)

build/debug/%.o: LIB_NASMFLAGS += -g
build/debug/%.o: src/%.asm
	@mkdir -p $(dir $@)
	@nasm $< -o $@ $(LIB_NASMFLAGS)

build/tests/%.o: tests/%.c
	@mkdir -p $(dir $@)
	@gcc -c $< -o $@ $(TESTS_CPPFLAGS) $(TESTS_CFLAGS)
