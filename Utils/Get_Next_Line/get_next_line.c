/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoujdam <agoujdam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 15:22:37 by agoujdam          #+#    #+#             */
/*   Updated: 2024/01/22 15:34:14 by agoujdam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *str, int fd)
{
	char	*buf;
	int		red;

	red = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_strchr(str, '\n') && red)
	{
		red = read(fd, buf, BUFFER_SIZE);
		if (red == -1)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		buf[red] = '\0';
		str = ft_strjoin(str, buf, 0);
		if (!str)
			return (NULL);
	}
	free(buf);
	return (str);
}

char	*ft_line(char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str[0])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		ret = malloc(i + 2);
	else
		ret = malloc(i + 1);
	if (!ret)
		return (NULL);
	while (j <= i && str[j])
	{
		ret[j] = str[j];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	*ft_clean(char *save)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
		return (free(save), NULL);
	i++;
	ret = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!ret)
		return (free(save), NULL);
	while (save[i])
	{
		ret[j] = save[i];
		j++;
		i++;
	}
	ret[j] = '\0';
	free(save);
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	save = ft_read(save, fd);
	if (!save)
		return (NULL);
	line = ft_line(save);
	save = ft_clean(save);
	return (line);
}
