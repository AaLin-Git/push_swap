CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

NAME = push_swap

SRCS = srcs/main.c srcs/add_node.c srcs/validation.c srcs/helper.c srcs/swap.c srcs/push.c \
srcs/rotate.c srcs/reverse_rotate.c srcs/small_sort.c srcs/chunk_sort.c srcs/assign_index.c srcs/main_sort.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libs/Libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)


%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re