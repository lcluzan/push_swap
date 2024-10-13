NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Werror -Wextra

SRC_PATH = src/
OBJ_PATH = obj/

SRC		= main.c \
		input_checker.c \
		utils_checker.c \
		initialisation.c \
		stack.c \
		swap.c \
		push.c \
		rotate.c \
		rev_rotate.c \
		small_sort.c \
		sort.c \
		position.c \
		cost.c \
		move.c \
		utils.c
SRCS	= $(addprefix $(SRC_PATH), $(SRC))
OBJ		= $(SRC:.c=.o)
OBJS	= $(addprefix $(OBJ_PATH), $(OBJ))
INCS	= -I ./includes/

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test2 test3 test5 test100 test500 test1000
