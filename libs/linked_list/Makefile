CC =	cc
CFLAGS =	-Wall -Wextra -Werror
RM =	rm -f
NAME =	linked_list.a
SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
ft_lstclear.c
DEST =	$(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME) : $(DEST)
	@ar rcs $(NAME) $(DEST)

clean :
	@$(RM) $(DEST)

fclean : clean
	@$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re
