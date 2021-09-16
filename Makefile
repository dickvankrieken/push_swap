NAME_PS =			push_swap

NAME_C =			checker

SRCS_SHARED =		srcs/stacks.c srcs/utils.c srcs/swap.c srcs/push.c srcs/rotate.c srcs/error.c
OBJS_SHARED =		$(SRCS_SHARED:.c=.o)

SRCS_PS = 			srcs/push_swap.c
OBJS_PS =			$(SRCS_PS:.c=.o)

SRCS_C =			srcs/checker.c srcs/checker_utils.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
OBJS_C =			$(SRCS_C:.c=.o)

SRC_DIR =			srcs/

LIBFT =				libft/libft.a

CFLAGS =			-Wall -Werror -Wextra

all: $(NAME_PS) $(NAME_C)

$(NAME_PS): $(OBJS_PS) $(OBJS_SHARED) $(LIBFT)
	$(CC) -g -fsanitize=address $(CFLAGS) -o $(NAME_PS) $(LIBFT) $(OBJS_PS) $(OBJS_SHARED)

$(NAME_C): $(OBJS_C) $(OBJS_SHARED) $(LIBFT)
	$(CC) -g -fsanitize=address $(CFLAGS) -o $(NAME_C) $(LIBFT) $(OBJS_C) $(OBJS_SHARED)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) -g -fsanitize=address $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(addprefix $(SRC_DIR),*.o)
	make -C libft clean

fclean: clean
	rm -f $(NAME_PS)
	rm -f $(NAME_C)

re: fclean all

.PHONY: all clean fclean re
