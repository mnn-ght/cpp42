#################### SETUP ####################
NAME = program
CC = c++

FLAGS = -Wall -Wextra -Werror
CPPFLAG = -std=c++98

#################### PATH ####################
OBJ_PATH = .obj/

#################### SRC & OBJ ####################
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

#################### RULES ####################
all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: %.cpp
	@$(CC) $(FLAGS) $(CPPFLAG) -c $< -o $@

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
	./$(NAME) 12 Didier

val:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./$(NAME)