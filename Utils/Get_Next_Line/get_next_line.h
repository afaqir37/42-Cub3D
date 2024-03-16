/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <afaqir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:38:40 by agoujdam          #+#    #+#             */
/*   Updated: 2024/03/16 02:40:05 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include "../../cub3d.h"

char	*ft_strchr(char *str, char c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2, int j);
int		ft_strlen(char *str);
char	*ft_read(char *str, int fd);
char	*ft_line(char *str);
char	*ft_clean(char *save);
char	*get_next_line(int fd);

#endif