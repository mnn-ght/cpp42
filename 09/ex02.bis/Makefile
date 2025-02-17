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
error: all
	@printf "\n\e[1;32m====== TEST 1: un seul nombre ======\e[0m\n"
	./$(NAME) 3
	@printf "\n\e[1;32m====== TEST 2: un nombre negatif ======\e[0m\n"
	./$(NAME)  "-1" "2"
	@printf "\n\e[1;32m====== TEST 3 : un doublon ======\e[0m\n"
	./$(NAME) 1 5 4 4
	@printf "\n\e[1;32m====== TEST 4 : nombre > INT_MAX ======\e[0m\n"
	./$(NAME) 1 5 4 2147483648
	@printf "\n\e[1;32m====== TEST 4 : format ======\e[0m\n"
	./$(NAME) "1 4 5 2"

run: all
	./$(NAME) 7 8 5 11 9 0 2 1 10 3 4 6 12

run2: all
	./$(NAME) 2 18 15 20 5 9 13 14 19 17 3
	./$(NAME) 3 5 9 7 4

10: all
	./$(NAME) `shuf -i 1-10 -n 10 | tr "\n" " "`

100: all
	./$(NAME) `shuf -i 1-100 -n 100 | tr "\n" " "`

3000: all
	./$(NAME) `shuf -i 1-3000 -n 3000 | tr "\n" " "`

run3: all
	./$(NAME) 3 1 7 9 4 8 10 5 6 2
	./$(NAME) 10 2 5 7 6 8 3 9 4 1
	
val:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./$(NAME) `shuf -i 1-20 -n 11 | tr "\n" " "`