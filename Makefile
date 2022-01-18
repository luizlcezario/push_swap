NAME=push_swap

LIBFT = ./libft/libft.a
FILES=main.c push_swap.c init_stacks.c new_stack.c verify_duplicates.c errors.c\
	quick_sort.c rotates.c pushs.c reverses.c swaps.c

SRC=$(addprefix ./src/, $(FILES))
CFLAGS= -Wall -Wextra -Werror -o $(NAME)
all:$(NAME)

$(NAME): $(LIBFT)
	@gcc -I ./src/headers $(SRC) -L ./libft -lft $(CFLAGS)

$(LIBFT):
	@make others -C ./libft

clean:
	rm $(LIBFT)

fclean: clean
	rm $(NAME)

re: fclean all

teste: re
	./push_swap 1 3 2 10 5 32 4 42 12 31 33 34 55 6 65 76 -1 

.PHONY:all clean fclean re teste