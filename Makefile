NAME = push_swap
CHECKER = checker
LIBFT = ./libft/libft.a
MOVES = rotates.c pushs.c reverses.c swaps.c
G_ALGO = g_algo_utils_2.c g_algo_utils_3.c g_algo_utils.c
INIT = init.c new_stack.c verify_duplicates.c
M_ALGO = m_algo_utils.c
UTILS = errors.c quick_sort.c verify_order.c $(addprefix init/, $(INIT)) \
	$(addprefix g_algo/, $(G_ALGO)) $(addprefix m_algo/, $(M_ALGO))
FILES = main.c g_algo.c m_algo.c $(addprefix moves/, $(MOVES)) \
	$(addprefix utils/, $(UTILS))
SRC= $(addprefix src/, $(FILES))

FILES_BONUS = main.c checker.c errors.c verify_order.c quick_sort.c \
	$(addprefix init/, $(INIT)) \
	$(addprefix moves/, $(MOVES))

SRC_BONUS = $(addprefix src_bonus/, $(FILES_BONUS))

LIB = -L ./libft -lft
CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(LIBFT)
	gcc $(CFLAGS) -I ./src/headers $(SRC) -g3 -o $(NAME) $(LIB)

$(CHECKER): $(LIBFT)
	gcc $(CFLAGS) -I ./src_bonus/headers $(SRC_BONUS) -o $(CHECKER) $(LIB) -g3

$(LIBFT):
	make others -C ./libft

clean:
	make -C libft fclean

fclean: clean
	make -C libft fclean
	rm -f $(NAME)
	rm -f $(CHECKER)

re: fclean all

reb: fclean bonus

view: re
	python3 -m push_swap_gui

.PHONY: all clean fclean re bonus reb