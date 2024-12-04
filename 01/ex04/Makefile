#################### SETUP ####################
NAME = program
CC = c++

FLAGS = -Wall -Wextra -Werror -g3
CPPFLAG = -std=c++98

#################### PATH ####################
SRC_PATH = src/
OBJ_PATH = obj/

#################### SRC & OBJ ####################
SRC = main.cpp
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ = $(SRC:.cpp=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

#################### RULES ####################
all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
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
	@rm -f test_file/*.replace

re: fclean all

#################### RULES ####################
run: all
	./$(NAME) test_file/file1 World monde

run2: all
	./$(NAME) test_file/emptyfile World monde

run3: all
	./$(NAME) test_file/no_authorization World monde

ARG = test_file/no_authorization World monde
val:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME) $(ARG)