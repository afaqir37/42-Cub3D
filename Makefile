CFLAGS = #-Wall -Wextra -Werror
SRC = main.c Parsing/check_first_errors.c Parsing/file_init.c \
	Parsing/fill_info.c Parsing/main_parsing.c Parsing/map_validity.c \
	Utils/Utils_1.c Utils/Utils_2.c Utils/Utils_3.c \
	Utils/Utils_4.c Utils/Utils_5.c Utils/Utils_6.c \
	Utils/Utils_7.c Utils/Get_Next_Line/get_next_line.c \
	Raycasting/data_initializer.c Raycasting/player_initializer.c \
	Raycasting/raycaster.c Raycasting/utils.c \
	Raycasting/line_drawer.c Raycasting/events.c \
	Raycasting/map_drawer.c Raycasting/update.c
OBJ = $(SRC:.c=.o)
LIBFT = libft.a
RM = rm -rf
NAME = cub3d

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) libft/libft.a -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

$(LIBFT):
	make -C libft

clean: 
	make clean -C libft
	$(RM) $(OBJ)

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re: fclean all