NAME =			push_swap
SRCS = 			srcs/push_swap.c srcs/stacks.c srcs/utils.c srcs/swap.c srcs/push.c srcs/rotate.c srcs/error.c
OBJS =			$(SRCS:.c=.o)

SRC_DIR =			srcs/

LIBFT =				libft/libft.a

CFLAGS =			-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_SHARED) $(LIBFT)
	$(CC) -g -fsanitize=address $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJS)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) -g -fsanitize=address $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(addprefix $(SRC_DIR),*.o)
	make -C libft clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
