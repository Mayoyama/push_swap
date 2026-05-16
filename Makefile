CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS =	main.c \
		algo_helpers/get_above_med.c \
		algo_helpers/cost_calculation.c \
		algo_helpers/ft_putdouble_fd.c \
		benchmark/benchmark.c \
		mode_complex/complex_mode.c \
		mode_complex/complex_mode_helpers.c \
		mode_medium/medium_mode.c \
		mode_medium/chunk_utils.c \
		mode_medium/handle_chunks.c \
		mode_medium/chunk_reinsertion.c \
		mode_simple/simple_mode.c \
		mode_adaptive/adaptive_mode.c \
		small_list/handle_small_list.c 
		
SRCS_SHARED =	push_operations/op_push.c \
				push_operations/op_reverse_rotate.c \
				push_operations/op_rotate.c \
				push_operations/op_swap.c \
				algo_helpers/stack_struct_functions.c \
				algo_helpers/algo_utils.c \
				input_parser/check_input.c \
				input_parser/parser_utils.c \
				mode_adaptive/disorder_checker.c \
				input_parser/input_struct_functions.c \
				input_parser/num_struct_functions.c \
				input_parser/extract_input.c 
				
SRCS_BONUS =	bonus_checker/main_checker.c \
				bonus_checker/check_op_push.c \
				bonus_checker/check_op_reverse_rotate.c \
				bonus_checker/check_op_rotate.c \
				bonus_checker/check_op_swap.c 

LIBFT = libft/libft.a
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS_SHARED = $(SRCS_SHARED:.c=.o)
OBJS_ALL = $(OBJS) $(OBJS_BONUS) $(OBJS_SHARED)
NAME = push_swap
NAME_BONUS = checker

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(OBJS_SHARED)
	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft

$(OBJS): %.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_SHARED): %.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

clean:
	rm -f $(OBJS_ALL)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	$(MAKE) -C libft fclean

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(OBJS_SHARED) $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft

$(OBJS_BONUS): %.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean bonus re
