#include "checker.h"

int	len_of_nb(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len = 1;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

t_data	*create_data(int argc)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		return (0);
	new->size = argc - 1;
	new->array = malloc(sizeof(int) * new->size);
	new->second_array = malloc(sizeof(int) * new->size);
	if (!new->array || !new->second_array)
	{
		delete_data(new);
		return (0);
	}
	new->size2 = 0;
	new->bonus = 0;
	return (new);
}

void	delete_data(t_data *data)
{
	if (data)
	{
		if (data->array)
			free(data->array);
		if (data->second_array)
			free(data->second_array);
		free(data);
	}
}

int	is_bonus(t_data *data, char **argv)
{
	if (ft_strlen(argv[1]) == 2 && argv[1][0] == '-' && argv[1][1] == 'v')
	{
		data->bonus = 1;
		return (2);
	}
	return (1);
}

void	create_array_of_int(t_data *data, int argc, char **argv)
{
	int	i;
	int	j;

	i = is_bonus(data, argv);
	data->size = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) || argv[i][j] == '-')
			{
				data->array[data->size] = ft_atoi(&argv[i][j]);
				while (argv[i][j] && argv[i][j] != ' ')
					j++;
				data->size++;
				j--;
			}
			j++;
		}
		i++;
	}
}
