NAME=push_swap

LIBFT = ./libft/libft.a

MOVES = rotates.c pushs.c reverses.c swaps.c

UTILS = new_stack.c verify_duplicates.c errors.c quick_sort.c \
		 verify_order.c push_swap_utils.c mini_push_swap_utils.c

FILES = main.c push_swap.c finishing_swap.c init_stacks.c mini_push_swap.c\
		$(addprefix moves/, $(MOVES)) $(addprefix utils/, $(UTILS)) 

SRC=$(addprefix src/, $(FILES))
CFLAGS= -Wall -Wextra -Werror -o $(NAME)
all:$(NAME)

$(NAME): $(LIBFT)
	@gcc -g3 -I ./src/headers $(SRC) -L ./libft -lft $(CFLAGS)

$(LIBFT):
	@make others -C ./libft

clean:
	rm $(LIBFT)

fclean: clean
	rm $(NAME)

re: fclean all

teste: re
	./push_swap 450 583 925 888 153 580 596 612 235 618 547 111 374 911 818 426 323 690 320 595 882 669 979 667 995 923 655 917 564 683 366 147 607 253 300 187 849 912 421 466 459 532 840 369 349 265 691  38 585 286 920 264 587 248 509 902 798  73 163 220 192 416 520 378 431 799 730 889 330 569 258 678 834 948 716 418 233 636 670 497 222 918 731 820 175 804 404 338 24 754 543 973  17 771 746 862 101 315 119 778

teste2: 
	./push_swap 450 583 925 888 153 580 596 612 235 618 547 111 374 911 818 426 323 690 320 595 882 669 979 667 995 923 655 917 564 683 366 147 607 253 300 187 849 912 421 466 459 532 840 369 349 265 691  38 585 286 920 264 587 248 509 902 798  73 163 220 192 416 520 378 431 799 730 889 330 569 258 678 834 948 716 418 233 636 670 497 222 918 731 820 175 804 404 338 24 754 543 973  17 771 746 862 101 315 119 778

view: re
	python3 -m push_swap_gui

.PHONY:all clean fclean re teste view