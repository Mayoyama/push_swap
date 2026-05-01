CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = 	main.c \
		input_parser/check_input.c \
		input_parser/parser_utils.c
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
