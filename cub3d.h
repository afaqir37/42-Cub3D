/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 05:35:41 by afaqir            #+#    #+#             */
/*   Updated: 2024/03/16 20:36:26 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define TILE_SIZE 32
# define SCREEN_WIDTH 1440
# define SCREEN_HEIGHT 810
# define FOV 60.0
# define PRECISION 2.0
# define SQUARE_SIZE 59

typedef struct s_image
{
	void				*img;
	char				*addr;
	int					width;
	int					height;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_image;

typedef struct s_rgb
{
	int					r;
	int					g;
	int					b;
}						t_rgb;

typedef struct s_info
{
	char				*no;
	t_image				*no_img;
	char				*so;
	t_image				*so_img;
	char				*we;
	t_image				*we_img;
	char				*ea;
	t_image				*ea_img;
	t_rgb				f;
	t_rgb				c;
	char				**map;
}						t_info;

typedef struct s_file
{
	int					index;
	char				*line;
	struct s_file		*prev;
	struct s_file		*next;
}						t_file;

typedef struct skyler
{
	size_t				i;
	int					sign;
	unsigned long long	result;
}						t_need;

// Utils -----------------------------------------------------------------------

char	*ft_strchr(char *str, char c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2, int j);
char	*ft_read(char *str, int fd);
char	*ft_line(char *str);
char	*ft_clean(char *save);
char	*get_next_line(int fd);

// -----------------------------------------------------------------------------

// Parsing ---------------------------------------------------------------------

// --------------------------- /Parsing ------------------------------------

int		ft_arg_num(int ac);
int		ft_string(char *str, char *look);
int		ft_check_existance(char *str);
int		ft_check_line_blank(t_file *file, t_info *info);
int		ft_error_args(int ac, char **av);
void	ft_intialize_file(t_file **file, int fd);
int		ft_check_if_xpm_file_existance(t_file *file);
int		ft_check_rgb(t_file *file);
int		ft_skip_ec(char *str);
int		ft_check_if_file_has_unwanted_lines(t_file *file, t_info *info);
int		ft_check_infos_existance(t_file *file);
int		ft_check_info(t_file *file);
void	fill_directions(t_info **tm, t_file *file);
void	fill_colors(t_info **tm, t_file *file);
int		ft_fill_tmp(t_info **info, t_file *file);
int		ft_parse_args(int ac, char **av, t_info **inf, t_file **fle);
int		ft_fill_info(t_info **info, t_file **file);
int		ft_check_one_player(t_file *file, int line_start);
int		ft_nor_m_ap(t_file *tmp, int i);
int		ft_check_lines_after(t_file *file, int line_start, int i);
int		ft_how_many_nodes(t_file *file);
char	**ft_extract_map(t_file *file, int i);
int		ft_frt(t_file **file, t_info **info, char *str);
int		ft_check_map_validity(t_file *file, t_info **info);
int		ft_check_map_lenght(t_file *file, int line_start);
int		ft_return_index_of_first_line(t_file *file);
int		ft_check_first_last(t_file *tmp, int j);
int		ft_check_first_char(t_file *tmp);
int		ft_check_map_is_closed(t_file *file, int line_start);

// --------------------------- /Utils --------------------------------------

size_t	ft_lenstr(char *str);
int		ft_isemptychar(char c);
int		ft_return_len(char *str, int start);
int		ft_cmp_nnull(char *s1, char *s2, int i);
char	*ft_sbstr(char *str, int start, int len);
int		ft_wr(char *str);
int		ft_is_it_a_map_character(char c);
int		ft_is_the_whole_line_space(char *str);
t_file	*ft_return_index_line(t_file *file, int line_start);
int		ft_is_theretwoplus(char *str);
int		ft_check_last_line(t_file *file, int line_start);
t_file	*ft_return_node_with_index(t_file *file, int index);
void	ft_free_t_file_node(t_file **file);
void	ft_print_t_file(t_file *file);
int		ft_check_sentence_existance(t_file *file, char *str);
t_file	*ft_rnwi(t_file *file, char *str);
int		ft_does_have_content(t_file *file, char *str);
int		ft_rs(char *str, char *lookingfor);
int		ft_check_if_exists(t_file *file, char *name);
int		ft_how_many_commas(char *str);
int		ft_return_end(char *str, char *lookingfor);
int		ft_rgb_codes(t_file *file, char *name);
int		ft_check_line_nm(char *str, int i);
int		ft_number_seperated_bycomma(char *str, int i);
int		ft_is_the_whole_line_full_of_spaces(char *str);
int		ft_check_full_line(char *str, int i);
int		ft_to_find(char *string, char *lookingfor, int i, int j);
int		ft_to_find_index(char *string, char *lookingfor, int i, int j);

int		ft_free_info(t_info **info);
int		ft_free_file(t_file **file);
t_image	*load_xpm_file(void *mlx_ptr, const char *file_name);

// -----------------------------------------------------------------------------

// Raycasting ------------------------------------------------------------------

typedef struct s_player
{
	double				x;
	double				y;
	double				player_dir;
	int					turn_direction;
	int					walk_direction;
	int					side_direction;
	double				move_speed;
	double				rotation_speed;
	double				rotation_angle;
}						t_player;

typedef struct s_ray
{
	double				x;
	double				y;
	double				angle;
	double				distance;
	int					is_horizontal;
	int					up;
	int					down;
	int					left;
	int					right;
}						t_ray;

typedef struct s_pack
{
	float				wall_top;
	float				wall_bottom;
	float				wall_height;
	int					i;
}						t_pack;

typedef struct s_horz
{
	float				wall_hit_x;
	float				wall_hit_y;
	float				wall;
	float				distance;
}						t_horz;

typedef struct s_vert
{
	float				wall_hit_x;
	float				wall_hit_y;
	float				wall;
	float				distance;
}						t_vert;

typedef struct s_direction
{
	int					up;
	int					down;
	int					left;
	int					right;
}						t_direction;

typedef struct s_intersection
{
	float				xintercept;
	float				yintercept;
	float				xstep;
	float				ystep;
	float				next_x;
	float				next_y;
}						t_intersection;

typedef struct s_img
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_img;

typedef struct s_data
{
	void				*mlx;
	void				*win;
	char				**map;
	int					screen_width;
	int					screen_height;
	double				field_of_view;
	double				half_of_fov;
	double				increment_angle;
	double				precision;
	t_player			player;
	t_img				img;
	t_info				*info;
	t_ray				*rays;
	t_image				*texture;
	t_file				*file;
}						t_data;

double	_to_radian(double degree);
double	_to_degree(double radian);
int		_initialize(t_data *data, t_info *info, char **map);
double	_direction(int c);
void	_init_player(char **map, t_player *player);
void	_draw_line(t_data *data, float ray_angle, int i,
			float dist_to_proj);
void	_ray_casting(t_data *data);
int		_event_listener(int key, t_data *data);
void	_draw_map(t_data *data);
int		_key_press_listener(int key, t_data *data);
int		_key_release_listener(int key, t_data *data);
void	_update(t_data *data);
double	_normalize_angle(double radiant_angle);
int		_ray_facing_up(double radian);
int		_ray_facing_down(double radian);
int		_ray_facing_right(double radian);
int		_ray_facing_left(double radian);
double	_normalize_angle(double radian_angle);
int		_has_wall_at(double x, double y, t_data *data);
void	_horizontal_intersect(t_intersection *inter,
			t_data *data, float ray_angle, t_direction dir);
void	_horizontal_dda(t_data *data, t_horz *horz,
			t_intersection *inter, int up);
void	_vertical_intersect(t_intersection *inter, t_data *data,
			float ray_angle, t_direction dir);
void	_vertical_dda(t_data *data, t_vert *vert,
			t_intersection *inter, int left);
void	my_mlx_pixel_put(t_img img, int x, int y,
			unsigned int color);
void	_move_vertical(t_data *data);
void	_move_horizontal(t_data *data);
void	_rotate(t_data *data);
void	_paint(t_data *data);

int		_set_texture(t_data *data, float ray_angle, int i);
void	_render_the_world(t_data *data, t_pack *pack,
			int texture_offset_x);
void	_horz_vert_choice(t_data *data, t_horz *horz,
			t_vert *vert, int i);
size_t	rgb_to_hex(int r, int g, int b);
void	_set_player(char **map, t_player *player, int i, int j);

// -----------------------------------------------------------------------
#endif
