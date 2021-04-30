#include "push_swap.h"

t_data	*create_data(int argc)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		return (0);
	new->size = argc - 1;
	new->array = malloc(sizeof(int) * new->size);
	new->second_array = malloc(sizeof(int) * new->size);
	new->a_moves = malloc(sizeof(int) * new->size);
	new->b_moves = malloc(sizeof(int) * new->size);
	new->b_ways = malloc(sizeof(t_ways) * new->size);
	if (!new->array || !new->second_array || !new->a_moves || !new->b_moves
		|| !new->b_ways)
	{
		delete_data(new);
		return (0);
	}
	new->size2 = 0;
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
		if (data->a_moves)
			free(data->a_moves);
		if (data->b_moves)
			free(data->b_moves);
		if (data->b_ways)
			free(data->b_ways);
		free(data);
	}
}

void	create_array_of_int(t_data *data, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
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

void	ps_error(t_data *data)
{
	delete_data(data);
	ft_putstr("Error\n");
	exit(1);
}
