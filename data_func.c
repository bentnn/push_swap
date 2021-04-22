#include "checker.h"

t_data *create_data(int argc)
{
	t_data	*new;

	new = malloc(sizeof(t_data));
	if (!new)
		return (0);
	new->size = argc - 1;
	new->array = malloc(sizeof(int) * new->size);
	if (!new->array)
	{
		free(new);
		return (0);
	}
	return (new);
}

void delete_data(t_data *data)
{
	if (data)
	{
		if (data->array)
			free(data->array);
		free(data);
	}
}

void create_array_of_int(t_data *data, int argc, char **argv)
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