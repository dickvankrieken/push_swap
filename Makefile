NAME_PS = push_swap

NAME_C = checker

SRC_DIR = srcs/

SRCFILES_PS = push_swap.c \
	utils.c \
	swap.c \
	push.c

SRCS_PS = $(addprefix $(SRC_DIR),$(SRCFILES_PS))

SRCS_C = checker.c

OBJ_DIR = objs/

OBJS_PS = $(addprefix $(OBJ_DIR),$(SRCFILES_PS:.c=.o))

LIBFT = libft/libft.a

CFLAGS = -Wall -Werror -Wextra

all: $(NAME_PS)

$(NAME_PS): $(OBJS_PS) $(LIBFT)
	$(CC) -g -fsanitize=address $(CFLAGS) -o $(NAME_PS) $(LIBFT) $(OBJS_PS)

$(NAME_C): $(OBJS_PS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME_C) $(LIBFT) $(OBJS_C)

$(LIBFT):
	make -C libft

$(addprefix $(OBJ_DIR),%.o): $(addprefix $(SRC_DIR),%.c)
	$(CC) -g -fsanitize=address $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(addprefix $(OBJ_DIR),*.o)

fclean: clean
	rm -f $(NAME_PS)
	rm -f $(NAME_C)

re: fclean all

.PHONY: all clean fclean re
