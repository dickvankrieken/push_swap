NAME =			push_swap

SRCS = 			srcs/push_swap.c srcs/stacks.c srcs/utils.c srcs/utils-2.c srcs/swap.c srcs/push.c srcs/rotate.c \
				srcs/reverse_rotate.c srcs/error.c srcs/nodes.c srcs/sort.c srcs/sort_four_five.c

OBJS =			$(SRCS:.c=.o)

SRC_DIR =		srcs/

LIBFT =			libft/libft.a

CFLAGS =		-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_SHARED) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJS)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(addprefix $(SRC_DIR),*.o)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
