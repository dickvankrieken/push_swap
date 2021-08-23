NAME_PS = push_swap

NAME_C = checker

SRCS_PS = push_swap.c

SRCS_C = checker.c

OBJS_PS = $(SRCS_PS:.c=.o)

LIBFT = libft/libft.a

CFLAGS = -Wall -Werror -Wextra

all: $(NAME_PS)

$(NAME_PS): $(OBJS_PS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_PS) $(LIBFT) $(OBJS_PS)

$(NAME_C): $(OBJS_PS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_C) $(LIBFT) $(OBJS_C)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
