CFLAGS = -Wall -Wextra -Werror -fsanitize=address
SRC = main.c Parsing/check_first_errors.c Parsing/file_init.c Parsing/freeing.c \
	Parsing/fill_info.c Parsing/main_parsing.c Parsing/map_validity.c Parsing/map_validity_norm.c\
	Utils/Utils_1.c Utils/Utils_2.c Utils/Utils_3.c \
	Utils/Utils_4.c Utils/Utils_5.c Utils/Utils_6.c \
	Utils/Utils_7.c Utils/Get_Next_Line/get_next_line.c Utils/Get_Next_Line/get_next_line_utils.c \
	Raycasting/data_initializer.c Raycasting/player_initializer.c \
	Raycasting/raycaster.c Raycasting/utils.c \
	Raycasting/line_drawer.c Raycasting/events.c \
	Raycasting/update.c \
	Raycasting/DDA.c Raycasting/DDA_utils.c \
	Raycasting/utils_extra.c Raycasting/texture_3d.c 
OBJ = $(SRC:.c=.o)
LIBFT = libft.a
RM = rm -rf
NAME = cub3D

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