CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -f

NAME = push_swap

SRCS = srcs/main.c srcs/validation.c srcs/list_manipulation.c srcs/clean.c srcs/small_sort.c \
srcs/push_swap.c srcs/rotate.c srcs/reverse_rotate.c srcs/small_sort.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libs/Libft
LIBFT = $(LIBFT_DIR)/libft.a

LLIST_DIR = libs/linked_list
LLIST = $(LLIST_DIR)/linked_list.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LLIST)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LLIST) -o $(NAME)

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

$(LLIST):
	@make -s -C $(LLIST_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@make -C $(LLIST_DIR) fclean

re: fclean all

.PHONY: all clean fclean re