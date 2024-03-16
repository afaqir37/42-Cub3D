CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c
RM = rm -rf
NAME = libft.a

all : $(NAME)

$(NAME) : $(SRC:.c=.o)
	ar rc libft.a $(SRC:.c=.o)

clean:
	$(RM) $(SRC:.c=.o) $(SRCBB:.c=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus
