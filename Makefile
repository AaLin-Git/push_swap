CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap

SRCS = srcs/main.c srcs/add_node.c srcs/validation.c srcs/helper.c srcs/swap.c srcs/push.c \
srcs/rotate.c srcs/reverse_rotate.c srcs/small_sort.c srcs/chunk_sort.c srcs/assign_index.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libs/Libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "linked successfully"

$(LIBFT):
	@make -s -C $(LIBFT_DIR)
	@echo "libft compiled correctly"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "compiled successfully"

clean:
	@$(RM) $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@echo "removed object files from push_swap"

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "removed $(NAME) and $(LIBFT)"

re: fclean all

.PHONY: all clean fclean re