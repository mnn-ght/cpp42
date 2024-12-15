#################### SETUP ####################
NAME = program
CC = c++

FLAGS = -Wall -Wextra -Werror -g3
CPPFLAG = -std=c++98

#################### PATH ####################
SRC_PATH = src/
OBJ_PATH = obj/

#################### SRC & OBJ ####################
SRC = main.cpp AMateria.cpp MateriaSource.cpp Character.cpp Cure.cpp Ice.cpp OnFloor.cpp
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRC:.cpp=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

#################### RULES ####################
all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@$(CC) $(FLAGS) $(CPPFLAG) -I ./includes -c $< -o $@

$(OBJ_PATH) :
	@mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -f $(NAME)

re: fclean all

#################### RULES ####################
run: all
	./$(NAME)

val:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./$(NAME)