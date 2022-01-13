NAME=push_swap

LIBFT = ./libft/libft.a
FILES=main.c push_swap.c pushs.c rotates.c swaps.c reverses.c

SRC=$(addprefix ./src/, $(FILES))
CFLAGS= -Wall -Wextra -Werror -o $(NAME)
all:$(NAME)

$(NAME): $(LIBFT)
	gcc -L ./libft -lft $(SRC) $(CFLAGS) 

$(LIBFT):
	make others -C ./libft

clean:
	rm $(LIBFT)

fclean: clean
	rm $(NAME)

re: fclean all

teste:
	./push_swap 2 3 4 5 6 232 13 12  40 2

.PHONY:all clean fclean re teste