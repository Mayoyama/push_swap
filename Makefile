CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = 
OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJS): %.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

valgrind: $(NAME)
	valgrind --leak-check=FULL --show-link-kinds=all ./$(NAME)

.PHONY: all clean fclean re valgrind
