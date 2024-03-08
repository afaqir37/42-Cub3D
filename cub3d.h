#ifndef _CUB3D_H_
# define _CUB3D_H_

# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# define TILE_SIZE 64
# define SCREEN_WIDTH 1920
# define SCREEN_HEIGHT 1080
# define FOV 60.0
# define PRECISION 2.0
# define SQUARE_SIZE 59


typedef struct {
    void *img;
	char *addr;
    int width;
    int height;
	int bits_per_pixel;
	int size_line;
	int endian;
} Image;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct s_info
{
	char			*NO;
	Image			*NO_img;
	char			*SO;
	Image			*SO_img;
	char			*WE;
	Image			*WE_img;
	char			*EA;
	Image			*EA_img;
	t_rgb			F;
	t_rgb			C;
	char			**map;
}					t_info;

typedef struct s_file
{
	int				index;
	char			*line;
	struct s_file	*prev;
	struct s_file	*next;
}					t_file;

typedef struct skyler {
	size_t				i;
	int					sign;
	unsigned long long	result;
}	t_need;


// Utils -----------------------------------------------------------------------

char				*ft_strchr(char *str, char c);
char				*ft_strdup(char *str);
char				*ft_strjoin(char *s1, char *s2, int j);
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
int					ft_to_find(char *, char *, int, int);
int					ft_cmp_nnull(char *, char *, int i);
int					ft_to_find_index(char *, char *, int, int);
int					ft_wr(char *);
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
int					ft_check_lines_after(t_file *, int, int);
int					ft_check_one_player(t_file *, int);
int					ft_check_last_line(t_file *, int);
t_file				*ft_return_node_with_index(t_file *, int);
int					ft_check_map_is_closed(t_file *, int);
int					ft_check_map_lenght(t_file *, int);
int					ft_check_map_validity(t_file *file, t_info **info);
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
int					ft_number_seperated_bycomma(char *, int);
int					ft_rgb_codes(t_file *, char *);
int					ft_check_rgb(t_file *);
int					ft_fill_tmp(t_info **, t_file *);
int					ft_fill_info(t_info **, t_file *);
void				ft_print_t_info(t_info *);
int					ft_check_if_file_has_unwanted_lines(t_file *);
int					ft_is_the_whole_line_full_of_spaces(char *);
int					ft_check_if_file_has_lines_filled_with_blank_characters(t_file *);
int					ft_parse_args(int, char **, t_info **, t_file **);
int					ft_check_one_player(t_file *, int);
int					ft_nor_m_ap(t_file *, int);
int					ft_skip_ec(char *str);
int					ft_check_full_line(char *str, int i);


// -----------------------------------------------------------------------------

// Raycasting -------------------------------------------------------------------

typedef struct s_player
{
	double				x;
	double				y;
	double			player_dir;
	int				turn_direction;
	int				walk_direction;
	int				side_direction;
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
    int				is_horizontal;
	int				up;
	int				down;
	int				left;
	int				right;
}					t_ray;

typedef struct s_pack
{
	double			wall_top;
	double			wall_bottom;
	double			wall_height;
	int				i;
}					t_pack;


typedef struct s_horz
{
	float		wall_hit_x;
	float		wall_hit_y;
	float		wall;
	float		distance;
}					t_horz;

typedef struct s_vert
{
	float		wall_hit_x;
	float		wall_hit_y;
	float		wall;
	float		distance;
}					t_vert;

typedef struct s_intersection
{
	float	xintercept;
	float	yintercept;
	float	xstep;
	float	ystep;
	float	next_X;
	float	next_Y;
}		t_intersection;

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
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	void 		  	*img;
	char			*img_data;
	t_info 			*info;
	t_ray			*rays;
	Image			*texture;
}					t_data;

double				_to_radian(double degree);
double				_to_degree(double radian);
int					_initialize(t_data* data, t_info *info, char **map);
double				_direction(int c);
void				_init_player(char **map, t_player *player);
void	_draw_line(t_data *data, float ray_angle, int i);
void                _ray_casting(t_data* data);
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
int					_has_wall_at(double x, double y, t_data *data);
void				_horizontal_intersect(t_intersection* inter, t_data* data, float ray_angle);
void				_horizontal_dda(t_data *data, t_horz *horz, t_intersection *inter, float ray_angle);
void				_vertical_intersect(t_intersection* inter, t_data* data, float ray_angle);
void				_vertical_dda(t_data *data, t_vert *vert, t_intersection *inter, float ray_angle);
void				my_mlx_pixel_put(t_data *data, int x, int y, unsigned int color);
int 				ft_max_strlen(char **str);
int 				ft_ret_ptr_nbr(char **str);
void	_move_vertical(t_data* data);
void	_move_horizontal(t_data* data);
void	_rotate(t_data* data);
void	_paint(t_data *data);
void	_horizontal_intersect(t_intersection* inter, t_data* data, float ray_angle);
void	_horizontal_dda(t_data *data, t_horz *horz, t_intersection *inter, float ray_angle);
void	_vertical_intersect(t_intersection* inter, t_data* data, float ray_angle);
void	_vertical_dda(t_data *data, t_vert *vert, t_intersection *inter, float ray_angle);
int		_set_texture(t_data *data, float ray_angle, int i);
void	_render_the_world(t_data *data, t_pack *pack, int texture_offset_x);
void	_horz_vert_choice(t_data *data, t_horz *horz, t_vert *vert, int i);
unsigned int rgb_to_hex(int r, int g, int b);

// -------------------------------------------------------------------------------
#endif
