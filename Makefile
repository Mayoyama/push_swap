CC = cc
# RETIRER  FSANITIZE FLAG
CFLAGS = -Wall -Werror -Wextra -fsanitize=address
SRCS =	main.c \
		algo_helpers/stack_struct_functions.c \
		algo_helpers/get_above_med.c \
		algo_helpers/cost_calculation.c \
		algo_helpers/utils.c \
		algo_helpers/ft_putdouble_fd.c \
		benchmark/benchmark.c \
		input_parser/check_input.c \
		input_parser/parser_utils.c \
		input_parser/input_struct_functions.c \
		input_parser/num_struct_functions.c \
		input_parser/extract_input.c \
		mode_adaptive/disorder_checker.c \
		mode_adaptive/adaptive_mode.c \
		mode_complex/complex_mode.c \
		mode_complex/complex_mode_helpers.c \
		mode_medium/medium_mode.c \
		mode_medium/utils.c \
		mode_medium/handle_chunks.c \
		mode_medium/chunk_reinsertion.c \
		mode_simple/simple_mode.c \
		small_list/handle_small_list.c \
		push_operations/op_push.c \
		push_operations/op_reverse_rotate.c \
		push_operations/op_rotate.c \
		push_operations/op_swap.c
SRCS_BONUS =	bonus_checker/main_checker.c \
				
LIBFT = libft/libft.a
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
NAME = push_swap
NAME_BONUS = checker

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft

$(OBJS): %.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	$(MAKE) -C libft fclean

re: fclean all

valgrind: $(NAME)
	valgrind ./$(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) $(OBJS) $(OBJS_BONUS)
	$(MAKE) all
	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft

$(OBJS_BONUS): %.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re valgrind
