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

	i = 1;
	while (i < argc)
	{
		data->array[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	data->size = argc - 1;
}
