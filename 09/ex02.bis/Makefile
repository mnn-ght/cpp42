#################### SETUP ####################
NAME = PmergeMe
CC = c++

FLAGS = -Wall -Wextra -Werror -g3
CPPFLAG = -std=c++98

#################### PATH ####################
SRC_PATH = src/
OBJ_PATH = obj/

#################### SRC & OBJ ####################
SRC = main.cpp PmergeMe.cpp
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
	./$(NAME) 7 8 5 11 9 0 2 1 10 3 4 6

run1: all
	@printf "\n\e[1;32m====== TEST 1 ======\e[0m\n"
	./$(NAME) 3 5 9 7 4
	@sleep 0.2
	@printf "\n\e[1;32m====== TEST 2 ======\e[0m\n"
	./$(NAME) `shuf -i 1-1000 -n 3000 | tr "\n" " "`
	@sleep 0.2
	@printf "\n\e[1;32m====== TEST 3 ======\e[0m\n"
	./$(NAME)  "-1" "2"
	@printf "\n\e[1;32m====== TEST 4 ======\e[0m\n"
	./$(NAME) `shuf -i 1-100000 -n 11 | tr "\n" " "`
	
val:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./$(NAME) 7 8 5 11 9 0 2 1 10 3 4 6