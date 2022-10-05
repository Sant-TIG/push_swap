S = srcs/
O = objs/
B = bonus/
M = mandatory/

NAME = push_swap
BONUS_NAME = checker

SRCS =  $M$Spush_swap.c\
		$M$Sft_quick_sort.c\
		$M$Sft_control_sort.c $M$Sft_sort_a.c $M$Sft_sort_b.c $M$Sft_treat_three_case.c\
		$M$Sft_check_args.c $M$Sft_check_list.c $M$Sft_check_sorted.c $M$Sft_check_sorted_b.c\
		$M$Sft_push.c $M$Sft_rotate.c $M$Sft_reverse_rotate.c $M$Sft_swap.c\
		$M$Sft_listlen.c $M$Sft_insert_nbr.c $M$Sft_insert_empty.c $M$Sft_insert_end.c $M$Sft_insert_begin.c $M$Sft_copy_list.c $M$Sft_free_list.c\
		$M$Sft_digit_str.c $M$Sft_isdigit.c  $M$Sft_split.c $M$Sft_strlen.c $M$Sft_atoi.c $M$Sft_free_args.c\

SRCS_BONUS = $B$Smain_bonus.c\
			 $B$Streat_args_bonus.c $B$Streat_args_utils_bonus.c $B$Streat_args_utils_bonus2.c\
			 $B$Serror_exit_bonus.c $B$Sfree_bonus.c\
			 $B$Sft_split_checker_bonus.c $B$Slinked_utils_bonus.c\
			 $B$Sget_input_bonus.c $B$Sget_input_utils_bonus.c\
			 $B$Sft_swap.c $B$Sft_rotate.c $B$Sft_push.c $B$Sft_reverse_rotate.c\
			 $B$Sprint.c
	
OBJS =  $M$Opush_swap.o\
		$M$Oft_quick_sort.o\
		$M$Oft_control_sort.o $M$Oft_sort_a.o $M$Oft_sort_b.o $M$Oft_treat_three_case.o\
		$M$Oft_check_args.o $M$Oft_check_list.o $M$Oft_check_sorted.o $M$Oft_check_sorted_b.o\
		$M$Oft_push.o $M$Oft_rotate.o $M$Oft_reverse_rotate.o $M$Oft_swap.o\
		$M$Oft_listlen.o $M$Oft_insert_nbr.o $M$Oft_insert_empty.o $M$Oft_insert_end.o $M$Oft_insert_begin.o $M$Oft_copy_list.o $M$Oft_free_list.o\
		$M$Oft_digit_str.o $M$Oft_isdigit.o  $M$Oft_split.o $M$Oft_strlen.o $M$Oft_atoi.o $M$Oft_free_args.o\

OBJS_BONUS = $B$Omain_bonus.o\
			 $B$Otreat_args_bonus.o $B$Otreat_args_utils_bonus.o $B$Otreat_args_utils_bonus2.o\
			 $B$Oget_input_bonus.o $B$Oget_input_utils_bonus.o\
			 $B$Oerror_exit_bonus.o $B$Ofree_bonus.o\
			 $B$Oft_split_checker_bonus.o $B$Olinked_utils_bonus.o\
			 $B$Oft_swap.o $B$Oft_rotate.o $B$Oft_push.o $B$Oft_reverse_rotate.o\
			 $B$Oprint.o

CC = gcc
CFLAGS =  -Wall -Werror -Wextra#-fsanitize=address -g3

RM = -rm -rf

all: mandatory bonus

mandatory: $(NAME)

$M$O:
	@echo "Creating Objects Folder...."
	mkdir $@
	@echo "Folder created."

$(OBJS): | $M$O

$(OBJS): $M$O%.o: $M$S%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Compiling mandatory...."
	$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "Mandatory compiled"

bonus: $(BONUS_NAME)

$B$O:
	@echo "Creating Objects Folder...."
	mkdir $@
	@echo "Folder created."

$(OBJS_BONUS): | $B$O

$(OBJS_BONUS): $B$O%.o: $B$S%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_NAME): $(OBJS_BONUS)
	@echo "Compiling bonus...."
	$(CC) $(CFLAGS) $^ -o $@
	@echo "Bonus compiled"

clean:
	$(RM) $(OBJS) $(OBJS_BONUS) $M$O $B$O

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re