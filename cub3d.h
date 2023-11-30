#ifndef _CUB3D_H_
#define _CUB3D_H_

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_rgb
{
    int r;
    int g;
    int b;
} t_rgb;

typedef struct s_info
{
    char *NO;
    char *SO;
    char *WE;
    char *EA;
    t_rgb F;
    t_rgb C;
} t_info;

typedef struct s_file
{
    int    index;
    char *line;
    struct s_file *prev;
    struct s_file *next;
} t_file;

// Utils -----------------------------------------------------------------------

char *ft_strchr(char *str, char c);
char *ft_strdup(char *str);
char *ft_strjoin(char *s1, char *s2);
char *ft_read(char *str, int fd);
char *ft_line(char *str);
char *ft_clean(char *save);
char *get_next_line(int fd);

// -----------------------------------------------------------------------------

// Parsing ---------------------------------------------------------------------

size_t ft_strlen(char *);
int ft_string(char *str, char *look);
int ft_isemptychar(char);
int ft_return_len(char *, int);
int ft_to_find(char *, char *);
int ft_compare_no_null(char *, char *);
int ft_to_find_no_space(char *, char *);
int ft_to_find_index(char *, char *);
int    ft_write_error(char *);
int ft_check_existance(char *);
char *ft_substr(char *, int, int);
int ft_error_args(int, char **);
void    ft_intialize_file(t_file **, int);
void ft_remove_empty_lines(t_file **);
int ft_is_it_a_map_character(char);
int    ft_is_the_whole_line_space(char *);
int ft_return_index_of_first_line(t_file *);
t_file *ft_return_index_line(t_file *, int);
int ft_is_theretwoplus(char *);
int ft_check_lines_after(t_file *, int);
int ft_check_one_player(t_file *, int);
int    ft_is_there_anything_other_than_space_and_one(t_file *, int);
int ft_check_last_line(t_file *, int);
t_file *ft_return_node_with_index(t_file *, int);
int ft_check_map_is_closed(t_file *, int);
int ft_check_map_lenght(t_file *, int);
int ft_check_map_validity(t_file *);
void    ft_free_t_file_node(t_file **);
void    ft_print_t_file(t_file *);
int ft_check_sentence_existance(t_file *, char *);
int ft_check_infos_existance(t_file *);
t_file *ft_rnwi(t_file *, char *);
int ft_does_have_content(t_file *, char *);
int ft_check_info(t_file *);
int ft_rs(char *, char *);
int ft_check_if_exists(t_file *, char *);
int ft_check_if_xpm_file_existance(t_file *);
int ft_how_many_commas(char *);
int ft_return_end(char *, char *);
int ft_number_seperated_bycomma(char *);
int ft_rgb_codes(t_file *, char *);
int ft_check_rgb(t_file *);
int ft_fill_tmp(t_info **, t_file *);
int    ft_fill_info(t_info **, t_file *);
void ft_print_t_info(t_info *);
int ft_check_if_file_has_unwanted_lines(t_file *);
int ft_is_the_whole_line_full_of_spaces(char *);
int ft_check_if_file_has_lines_filled_with_blank_characters(t_file *);
int    ft_parse_args(int, char **, t_info **, t_file **);

// -----------------------------------------------------------------------------

#endif
