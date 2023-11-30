#include "../../cub3D.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif

char    *ft_strchr(char *str, char c)
{
    unsigned int i = 0;
    if (!str)
        return(NULL);
    while(str[i])
    {
        if(str[i] == c)
            return(str + i);
        i++;
    }
    return(NULL);
}

char    *ft_strdup(char *str)
{
    unsigned int i = 0;
    char    *ret;
    if(!str)
        return(NULL);
    ret = malloc(sizeof(char) * (ft_strlen(str) + 1));
    while(str[i])
    {
        ret[i] = str[i];
        i++;
    }
    ret[i] = '\0';
    return(ret);
}

char    *ft_strjoin(char *s1, char *s2)
{
    int i = 0;
    int j = 0;
    char    *ret;
    if(!s2)
        return(NULL);
    if(!s1)
        return(ft_strdup(s2));
    ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if(!ret)
        return(NULL);
    while(s1[i])
    {
        ret[i] = s1[i];
        i++;
    }
    while(s2[j])
    {
        ret[i] = s2[j];
        i++;
        j++;
    }
    ret[i] = '\0';
    free(s1);
    return(ret);
}

char    *ft_read(char *str, int fd)
{
    char *buf;
    int red = 1;

    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!buf)
        return(NULL);
    while(!ft_strchr(str, '\n') && red)
    {
        red = read(fd, buf, BUFFER_SIZE);
        if(red == -1)
        {
            free(buf);
            free(str);
            return(NULL);
        }
        buf[red] = '\0';
        str = ft_strjoin(str, buf);
        if(!str)
            return(NULL);
    }
    free(buf);
    return(str);
}

char    *ft_line(char *str)
{
    char    *ret;
    int i = 0;
    int j = 0;
    if(!str[0])
        return(NULL);
    while(str[i] && str[i] != '\n')
        i++;
    if(str[i] == '\n')
        ret = malloc(i + 2);
    else
        ret = malloc(i + 1);
    if(!ret)
        return(NULL);
    while(j <= i && str[j])
    {
        ret[j] = str[j];
        j++;
    }
    ret[j] = '\0';
    return(ret);
}

char    *ft_clean(char  *save)
{
    char *ret;
    int i = 0;
    int j = 0;

    while(save[i] && save[i] != '\n')
        i++;
    if(!save[i])
    {
        free(save);
        return(NULL);
    }
    i++;
    ret = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
    if(!ret)
    {
        free(save);
        return(NULL);
    }
    while(save[i])
    {
        ret[j] = save[i];
        j++;
        i++;
    }
    ret[j] = '\0';
    free(save);
    return(ret);
}
char    *get_next_line(int fd)
{
    static char *save;
    char    *line;
    if(BUFFER_SIZE <= 0 || fd < 0)
        return (NULL);
    save = ft_read(save, fd);
    if(!save)
        return(NULL);
    line = ft_line(save);
    save = ft_clean(save);
    return(line);
}