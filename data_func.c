#include "checker.h"

t_data *create_data(int argc)
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

void delete_data(t_data *data)
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

//void output_stacks(t_data *data)
//{
//	int max;
//	int i;
//
//	max = data->size;
//	if (data->size2 > max)
//		max = data->size2;
//	i = 0;
//	while (i < max)
//	{
//		if (i < data->size)
//			ft_putstr(ft_itoa(data->array[i]));
//		else
//			ft_putchar(' ');
//		ft_putchar(' ');
//		if (i < data->size2)
//			ft_putstr(ft_itoa(data->second_array[i]));
//		else
//			ft_putchar(' ');
//		ft_putchar('\n');
//		i++;
//	}
//	ft_putstr("- -\na b\n");
//}

int len_of_nb(int nb)
{
	int len;

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

int find_max_len(int *array, int size)
{
	int max;
	int i;
	int new;

	if (size == 0)
		return (1);
	max = 0;
	i = 0;
	while (i < size)
	{
		new = len_of_nb(array[i]);
		if (new > max)
			max = new;
		i++;
	}
	return (max);
}

void put_spases(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar(' ');
		i++;
	}
}

void output_stacks(t_data *data)
{
	int max;
	int i;
	char *str;
	int max_len1;
	int max_len2;

	max = data->size;
	if (data->size2 > max)
		max = data->size2;
	max_len1 = find_max_len(data->array, data->size);
	max_len2 = find_max_len(data->second_array, data->size2);
	i = 0;
	while (i < max)
	{
		if (i < data->size)
		{
			str = ft_itoa(data->array[i]);
			ft_putstr(str);
			put_spases(max_len1 - ft_strlen(str) + 1);
			free(str);
		}
		else
			put_spases(max_len1 + 1);
		if (i < data->size2)
		{
			str = ft_itoa(data->second_array[i]);
			ft_putstr(str);
			free(str);
		}
		ft_putchar('\n');
		i++;
	}
	i = 0;
	while (i < max_len1)
	{
		ft_putchar('-');
		i++;
	}
	ft_putchar(' ');
	i = 0;
	while (i < max_len2)
	{
		ft_putchar('-');
		i++;
	}
	ft_putstr("\na");
	put_spases(max_len1);
	ft_putstr("b\n");
}
