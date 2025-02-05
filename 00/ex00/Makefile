NAME = megaphone
CC = c++

FLAGS = -Wall -Wextra -Werror
CPPFLAG = -std=c++98

SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) $(CPPFLAG) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all