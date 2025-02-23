#################### SETUP ####################
NAME = RPN
CC = c++

FLAGS = -Wall -Wextra -Werror -g3
CPPFLAG = -std=c++98

#################### PATH ####################
SRC_PATH = src/
OBJ_PATH = obj/

#################### SRC & OBJ ####################
SRC = main.cpp RPN.cpp
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

re: fclean all

#################### RULES ####################
run: all
	@printf "\e[1;32m====== TEST 1 (expected output: 42) ======\e[0m\n"
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@printf "\n\e[1;32m====== TEST 2 (expected output: 42) ======\e[0m\n"
	./$(NAME) "7 7 * 7 -"
	@printf "\n\e[1;32m====== TEST 3 (expected output: 0) ======\e[0m\n"
	./$(NAME) "1 2 * 2 / 2 * 2 4 - +"
	@printf "\n\e[1;32m====== TEST 4 (expected output: 1) ======\e[0m\n"
	./$(NAME) "1 2 + 3 /"
	@printf "\n\e[1;32m====== TEST 5 (expected output: 25) ======\e[0m\n"
	./$(NAME) "2 3 + 5 *"

error: all
	@printf "\e[1;32m====== TEST 1 ======\e[0m\n"
	./$(NAME) "(1 + 1)"
	@printf "\n\e[1;32m====== TEST 2 ======\e[0m\n"
	./$(NAME) "7 7 * 37 -"
	@printf "\n\e[1;32m====== TEST 3 ======\e[0m\n"
	./$(NAME) "2 3 + 5 * *"

val:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./$(NAME) "7 7 * 7 -"
