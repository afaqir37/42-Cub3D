#ifndef _CUB3D_H_
# define _CUB3D_H_

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define SCREEN_WIDTH 600 * 2
# define SCREEN_HEIGHT 600
# define MAP_SIZE 8
# define TILE_SIZE ((SCREEN_WIDTH / 2) / MAP_SIZE)
# define FOV 60.0
# define PRECISION 2.0
# define SQUARE_SIZE 59

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct s_info
{
	char			*NO;
	char			*SO;
	char			*WE;
	char			*EA;
	t_rgb			F;
	t_rgb			C;
}					t_info;

typedef struct s_file
{
	int				index;
	char			*line;
	struct s_file	*prev;
	struct s_file	*next;
}					t_file;

// Utils -----------------------------------------------------------------------

char				*ft_strchr(char *str, char c);
char				*ft_strdup(char *str);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_read(char *str, int fd);
char				*ft_line(char *str);
char				*ft_clean(char *save);
char				*get_next_line(int fd);

// -----------------------------------------------------------------------------

// Parsing ---------------------------------------------------------------------

size_t				ft_strlen(char *);
int					ft_string(char *str, char *look);
int					ft_isemptychar(char);
int					ft_return_len(char *, int);
int					ft_to_find(char *, char *);
int					ft_compare_no_null(char *, char *);
int					ft_to_find_no_space(char *, char *);
int					ft_to_find_index(char *, char *);
int					ft_write_error(char *);
int					ft_check_existance(char *);
char				*ft_substr(char *, int, int);
int					ft_error_args(int, char **);
void				ft_intialize_file(t_file **, int);
void				ft_remove_empty_lines(t_file **);
int					ft_is_it_a_map_character(char);
int					ft_is_the_whole_line_space(char *);
int					ft_return_index_of_first_line(t_file *);
t_file				*ft_return_index_line(t_file *, int);
int					ft_is_theretwoplus(char *);
int					ft_check_lines_after(t_file *, int);
int					ft_check_one_player(t_file *, int);
int					ft_is_there_anything_other_than_space_and_one(t_file *,
						int);
int					ft_check_last_line(t_file *, int);
t_file				*ft_return_node_with_index(t_file *, int);
int					ft_check_map_is_closed(t_file *, int);
int					ft_check_map_lenght(t_file *, int);
int					ft_check_map_validity(t_file *);
void				ft_free_t_file_node(t_file **);
void				ft_print_t_file(t_file *);
int					ft_check_sentence_existance(t_file *, char *);
int					ft_check_infos_existance(t_file *);
t_file				*ft_rnwi(t_file *, char *);
int					ft_does_have_content(t_file *, char *);
int					ft_check_info(t_file *);
int					ft_rs(char *, char *);
int					ft_check_if_exists(t_file *, char *);
int					ft_check_if_xpm_file_existance(t_file *);
int					ft_how_many_commas(char *);
int					ft_return_end(char *, char *);
int					ft_number_seperated_bycomma(char *);
int					ft_rgb_codes(t_file *, char *);
int					ft_check_rgb(t_file *);
int					ft_fill_tmp(t_info **, t_file *);
int					ft_fill_info(t_info **, t_file *);
void				ft_print_t_info(t_info *);
int					ft_check_if_file_has_unwanted_lines(t_file *);
int					ft_is_the_whole_line_full_of_spaces(char *);
int					ft_check_if_file_has_lines_filled_with_blank_characters(t_file *);
int					ft_parse_args(int, char **, t_info **, t_file **);

// -----------------------------------------------------------------------------

// Raycasting -------------------------------------------------------------------

typedef struct s_player
{
	double				x;
	double				y;
	double			player_dir;
	int				turn_direction;
	int				walk_direction;
	double			move_speed;
	double			rotation_speed;
	double			rotation_angle;
}					t_player;

typedef struct s_ray
{
	double			x;
	double			y;
	double			angle;
    double          distance;
    int             wall;
	double			horz_wall_hit_X;
	double			horz_wall_hit_Y;
	double			vert_wall_hit_X;
	double			vert_wall_hit_Y;
}					t_ray;

typedef struct s_data
{
    void*           mlx;
    void*           win;
	char**			map;
	int				screen_width;
	int				screen_height;
	double			field_of_view;
	double			half_of_FOV;
	double			increment_angle;
    double          precision;
	t_player		player;
}					t_data;

double				_to_radian(double degree);
double				_to_degree(double radian);
int                 _initialize(t_data *data, char **map);
double				_direction(int c);
void				_init_player(char **map, t_player *player);
void                _draw_line(t_data* data, int wall_height, int ray_count);
void                _ray_casting(t_data* data, char **map);
int					_event_listener(int key, t_data* data);
void				_draw_map(t_data* data);
int					_key_press_listener(int key, t_data* data);
int					_key_release_listener(int key, t_data* data);
void				_update(t_data* data);
void				draw_line(int x0, int y0, int x1, int y1, int color, t_data* data);
double				_normalize_angle(double radiant_angle);
int					_ray_facing_up(double radian);
int					_ray_facing_down(double radian);
int					_ray_facing_right(double radian);
int					_ray_facing_left(double radian);
double				_normalize_angle(double radian_angle);
int					_has_wall_at(double x, double y, char **map);
int					_horizontal_intersect(t_ray* ray, t_data* data);
int					_vertical_intersect(t_ray* ray, t_data* data);

// -------------------------------------------------------------------------------
#endif
