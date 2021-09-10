NAME_PS = push_swap

NAME_C = checker

SRC_DIR = srcs/

SRCFILES_SHARED = stacks.c \
	utils.c \
	swap.c \
	push.c \
	rotate.c

SRCS_SHARED = $(addprefix $(SRC_DIR),$(SRCFILES_SHARED))

SRCFILES_PS = push_swap.c

SRCS_PS = $(addprefix $(SRC_DIR),$(SRCFILES_PS))

SRCFILES_C = checker.c

SRCS_C = $(addprefix $(SRC_DIR),$(SRCFILES_C))

OBJ_DIR = objs/

OBJS_PS = $(addprefix $(OBJ_DIR),$(SRCFILES_PS:.c=.o))

OBJS_C = $(addprefix $(OBJ_DIR),$(SRCFILES_C:.c=.o))

OBJS_SHARED = $(addprefix $(OBJ_DIR),$(SRCFILES_SHARED:.c=.o))

LIBFT = libft/libft.a

CFLAGS = -Wall -Werror -Wextra

all: $(OBJ_DIR) $(NAME_PS) $(NAME_C)

$(NAME_PS): $(OBJS_PS) $(OBJS_SHARED) $(LIBFT)
	$(CC) -g -fsanitize=address $(CFLAGS) -o $(NAME_PS) $(LIBFT) $(OBJS_PS) $(OBJS_SHARED)

$(NAME_C): $(OBJS_C) $(OBJS_SHARED) $(LIBFT)
	$(CC) -g -fsanitize=address $(CFLAGS) -o $(NAME_C) $(LIBFT) $(OBJS_C) $(OBJS_SHARED)

$(LIBFT):
	make -C libft

$(addprefix $(OBJ_DIR),%.o): $(addprefix $(SRC_DIR),%.c)
	$(CC) -g -fsanitize=address $(CFLAGS) -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(addprefix $(OBJ_DIR),*.o)

fclean: clean
	rm -f $(NAME_PS)
	rm -f $(NAME_C)

re: fclean all

.PHONY: all clean fclean re
