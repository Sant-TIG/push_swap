C = check/
L = linked/
M = movements/
U = utils/
I = incs/

SRCS =  push_swap.c\
		$Lft_insert_nbr.c $Lft_print_list.c\
		$Cft_check_args.c $Cft_check_list.c $Cft_check_sorted.c\
		$Mft_push.c $Mft_reverse_rotate.c $Mft_rotate.c $Mft_swap.c\
		$Uft_atoi.c $Uft_isdigit.c $Uft_line_counter.c $Uft_split.c $Uft_strdigit.c $Uft_strlen.c\

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBC = ar rcs

RM = -rm -rf

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	@echo "Objects and directory cleaned!"

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re
