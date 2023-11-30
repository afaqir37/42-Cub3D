#include "../cub3D.h"

int ft_how_many_commas(char *str)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == ',')
			counter++;
		i++;
	}
	return (counter);
}

int ft_return_end(char *str, char *lookingfor)
{
	int i;

	i = ft_to_find_index(str, lookingfor);
	while (str[i])
	{
		if (ft_isemptychar(str[i]))
			i++;
		else
		{
			while(str[i])
			{
				if (ft_isemptychar(str[i]))
					break ;
				i++;
			}
			break ;
		}
	}
	return (i);
}

int ft_number_seperated_bycomma(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] != ',')
			return (-1);
		i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] != ',')
			return (-1);
		i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (-1);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		if (str[i] != '\0')
			return (-1);
	}
	return (0);
}

int ft_rgb_codes(t_file *file, char *name)
{
	t_file *tmp;
	char *str;
	int R;
	int G;
	int B;

	tmp = ft_rnwi(file, name);
	if (tmp == NULL)
		return (-1);
	str = ft_substr(tmp->line, ft_rs(tmp->line, name), ft_return_end(tmp->line, name) - ft_rs(tmp->line, name));
	if (!str)
		return (ft_write_error("Malloc Failed!"));
	if (ft_how_many_commas(str) != 2)
		return (free(str), ft_write_error("Invalid File: RGB codes must be separated by 2 commas!"));
	if (ft_number_seperated_bycomma(str) < 0)
		return (free(str), ft_write_error("Invalid File: RGB codes must be numbers!"));
	R = atoi(str);
	G = atoi(ft_strchr(str + 1, ',') + 1);
	B = atoi(ft_strchr(ft_strchr(str + 1, ',') + 1, ',') + 1);
	if (!(R >= 0 && R <= 255) || !(B >= 0 && B <= 255)  || !(G >= 0 && G <= 255) )
		return (free(str), ft_write_error("Invalid File: RGB codes must be between 0 and 255!"));
	free(str);
	return (0);
}