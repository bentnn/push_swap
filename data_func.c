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
	new->second_array = malloc(sizeof(int) * new->size);
	if (!new->second_array)
	{
		free(new->array);
		free(new);
		return (0);
	}
	new->size2 = 0;
	return (new);
}

void delete_data(t_data *data)
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

void output_stacks(t_data *data)
{
	int max;
	int i;

	max = data->size;
	if (data->size2 > max)
		max = data->size2;
	i = 0;
	while (i < max)
	{
		if (i < data->size)
			ft_putstr(ft_itoa(data->array[i]));
		else
			ft_putchar(' ');
		ft_putchar(' ');
		if (i < data->size2)
			ft_putstr(ft_itoa(data->second_array[i]));
		else
			ft_putchar(' ');
		ft_putchar('\n');
		i++;
	}
	ft_putstr("- -\na b\n");
}