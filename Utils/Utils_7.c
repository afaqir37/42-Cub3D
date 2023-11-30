#include "../cub3D.h"

int ft_to_find(char *string, char *lookingfor)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (string[i])
	{
		if (string[i] == lookingfor[j])
		{
			while (string[i] == lookingfor[j])
			{
				i++;
				j++;
			}
			if (lookingfor[j] == '\0')
			{	
				if (ft_isemptychar(string[i]))
					return (1);
				else
					return (0);
			}
			else
			{
				i = i - j;
				j = 0;
			}
		}
		i++;
	}
	return (0);
}



int ft_to_find_no_space(char *string, char *lookingfor)
{
	int i;
	int j;

	i = 0;
	j = 0;

	while (string[i])
	{
		if (string[i] == lookingfor[j])
		{
			while (string[i] == lookingfor[j])
			{
				i++;
				j++;
			}
			if (lookingfor[j] == '\0')
			{	
				return (0);
			}
			else
			{
				i = i - j;
				j = 0;
			}

		}
		i++;
	}
	if (lookingfor[j] != '\0')
		return (-1);
	return (0);
}

int ft_to_find_index(char *string, char *lookingfor)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (string[i])
	{
		if (string[i] == lookingfor[j])
		{
			while (string[i] == lookingfor[j])
			{
				i++;
				j++;
			}
			if (lookingfor[j] == '\0')
			{	
				if (ft_isemptychar(string[i]))
					return (i);
				else
					return (-1);
			}
			else
			{
				i = i - j;
				j = 0;
			}
		}
		i++;
	}
	return (-1);
}
