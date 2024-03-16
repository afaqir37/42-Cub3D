CC = cc
CFLAGS = #-Wall -Wextra -Werror
SRC = ft_atoi.c
RM = rm -rf
NAME = libft.a



all : $(NAME)

$(NAME) : $(SRC:.c=.o)
	ar rc libft.a $(SRC:.c=.o)

	
bonus :	ft_lstnew_bonus.o  ft_lstadd_front_bonus.o ft_lstsize_bonus.o ft_lstlast_bonus.o ft_lstadd_back_bonus.o ft_lstdelone_bonus.o ft_lstclear_bonus.o ft_lstiter_bonus.o ft_lstmap_bonus.o

ft_lstnew_bonus.o : ft_lstnew_bonus.c
	$(CC) $(CFLAGS) -c $<
	ar rc libft.a $@


ft_lstadd_front_bonus.o : ft_lstadd_front_bonus.c
	$(CC) $(CFLAGS) -c $<
	ar rc libft.a $@

ft_lstsize_bonus.o : ft_lstsize_bonus.c
	$(CC) $(CFLAGS) -c $<
	ar rc libft.a $@

ft_lstlast_bonus.o : ft_lstlast_bonus.c
	$(CC) $(CFLAGS) -c $<
	ar rc libft.a $@

ft_lstadd_back_bonus.o : ft_lstadd_back_bonus.c
	$(CC) $(CFLAGS) -c $<
	ar rc libft.a $@

ft_lstdelone_bonus.o : ft_lstdelone_bonus.c
	$(CC) $(CFLAGS) -c $<
	ar rc libft.a $@

ft_lstclear_bonus.o : ft_lstclear_bonus.c
	$(CC) $(CFLAGS) -c $<
	ar rc libft.a $@

ft_lstiter_bonus.o : ft_lstiter_bonus.c
	$(CC) $(CFLAGS) -c $<
	ar rc libft.a $@
	
ft_lstmap_bonus.o: ft_lstmap_bonus.c
	$(CC) $(CFLAGS) -c $<
	ar rc libft.a $@

clean:
	$(RM) $(SRC:.c=.o) $(SRCBB:.c=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY : all clean fclean re bonus
