#################### SETUP ####################
NAME = convert
CC = c++

FLAGS = -Wall -Wextra -Werror
CPPFLAG = -std=c++98

#################### PATH ####################
SRC_PATH = src/
OBJ_PATH = obj/

#################### SRC & OBJ ####################
SRC = main.cpp ScalarConverter.cpp
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
	@clear
	@printf "\e[1;31mcalculs en cours ◾◽◽◽◽◽◽◽\n"
	@sleep 0.2
	@clear
	@printf "calculs en cours ◾◾◽◽◽◽◽◽\n"
	@sleep 0.2
	@clear
	@printf "calculs en cours ◾◾◾◽◽◽◽◽\n"
	@sleep 0.2
	@clear
	@printf "calculs en cours ◾◾◾◾◽◽◽◽\n"
	@sleep 0.2
	@clear
	@printf "calculs en cours ◾◾◾◾◾◽◽◽\n"
	@sleep 0.2
	@clear
	@printf "calculs en cours ◾◾◾◾◾◾◽◽\n"
	@sleep 0.2
	@clear
	@printf "calculs en cours ◾◾◾◾◾◾◾◽\n"
	@sleep 0.2
	@clear
	@printf "calculs en cours ◾◾◾◾◾◾◾◾\e[0m\n"
	@sleep 0.2
	@clear
	@printf "\e[1;32mcalculs effectué ✅\e[0m\n"
	@sleep 0.4
	@clear
	@printf "\e[1;32m====== TEST 1 ======\e[0m\n"
	./$(NAME) 0
	@sleep 0.2
	@printf "\n\e[1;32m====== TEST 2 ======\e[0m\n"
	./$(NAME) nan
	@sleep 0.2
	@printf "\n\e[1;32m====== TEST 3 ======\e[0m\n"
	./$(NAME) 42.0f

val:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./$(NAME)