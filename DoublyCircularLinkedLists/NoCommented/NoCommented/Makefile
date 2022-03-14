S = srcs/
L = linked/
U = utils/
Q = quicksort/
P = print/
C = check/
M = movements/

NAME = push_swap

SRCS =  $Spush_swap.c\
		$S$Qft_quick_sort.c\
		$S$Pft_print_args.c $S$Pft_print_list.c\
		$S$Mft_push.c $S$Mft_rotate.c $S$Mft_reverse_rotate.c $S$Mft_swap.c\
		$S$Cft_check_args.c $S$Cft_check_list.c $S$Cft_check_sorted.c\
		$S$Lft_listlen.c $S$Lft_insert_nbr.c $S$Lft_insert_empty.c $S$Lft_insert_end.c $S$Lft_insert_begin.c\
		$S$Uft_digit_str.c $S$Uft_isdigit.c  $S$Uft_split.c $S$Uft_strlen.c $S$Uft_atoi.c\

CC = gcc
CFLAGS =  -Wall -Werror -Wextra #-fsanitize=address -g3

RM = -rm -rf

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

fclean:
	$(RM) $(NAME)

re: fclean all
