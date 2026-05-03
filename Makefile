CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = 	main.c \
		input_parser/check_input.c \
		input_parser/parser_utils.c \
		input_parser/input_struct_functions.c \
		input_parser/num_struct_functions.c \
		input_parser/extract_input.c \
		input_parser/get_index_and_target.c \
		push_operatations/op_push.c \
		push_operatations/op_reverse_rotate.c \
		push_operatations/op_rotate.c \
		push_operatations/op_swap.c \
		mode_adaptive/disorder_checker.c \
		mode_adaptive/adaptive_mode.c \
		helpers/ft_putdouble_fd.c \
		benchmark/benchmark.c \
		mode_complex/complex_mode.c
LIBFT = libft/libft.a
OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -Llibft -lft

$(OBJS): %.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

valgrind: $(NAME)
	valgrind --leak-check=FULL --show-link-kinds=all ./$(NAME)
.PHONY: all clean fclean re valgrind
