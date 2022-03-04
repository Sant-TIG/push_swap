S = srcs/
L = linked/
U = utils/

NAME = push_swap

SRCS =  $Spush_swap.c\
		$S$Lft_listlen.c $S$Lft_insert_nbr.c\
		$S$Uft_digit_str.c $S$Uft_isdigit.c  $S$Uft_split.c $S$Uft_strlen.c $S$Uft_atoi.c\

CC = gcc
CFLAGS =  -Wall -Werror -Wextra -fsanitize=address -g3

RM = -rm -rf

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@

fclean:
	$(RM) $(NAME)

re: fclean all
