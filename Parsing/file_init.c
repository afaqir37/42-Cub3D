#include "../cub3D.h"

void	ft_intialize_file(t_file **file, int fd)
{
    t_file *tmp;
    char *read;
    int i;

    i = 0;
    tmp = NULL;
    while ((read = get_next_line(fd)))
    {
        t_file *new_node = malloc(sizeof(t_file));
        new_node->line = read;
        new_node->index = i;
        new_node->next = NULL;
        new_node->prev = tmp; // Set the prev field to the previous node

        if (tmp == NULL)
        {
            (*file) = new_node;
        }
        else
        {
            tmp->next = new_node;
        }

        tmp = new_node;
        i++;
    }
}