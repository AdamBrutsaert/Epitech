##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAME = MyCat
SRC = MyCat.cpp
OBJ = $(SRC:%.cpp=build/release/%.o)

CXXFLAGS = -Wall -Wextra -g

all: $(NAME)

clean:
	@rm -rf build

fclean: clean
	@rm -f $(NAME)

re: fclean all

$(NAME): $(OBJ)
	@g++ -o $@ $^ $(LDFLAGS) $(LDLIBS)

build/release/%.o: %.cpp
	@mkdir -p $(dir $@)
	@g++ -c -o $@ $< $(CPPFLAGS) $(CXXFLAGS)
