#include "push_swap.h"

void	find_min_and_max(t_data *data, int *min, int *max)
{
	int	mn;
	int	mx;
	int	i;

	mn = 0;
	mx = 0;
	i = 0;
	while (i < data->size)
	{
		if (data->array[i] < data->array[mn])
			mn = i;
		if (data->array[i] > data->array[mx])
			mx = i;
		i++;
	}
	*max = mx;
	*min = mn;
}

void	count_struct_of_ways(t_data *data, int i, int bfr_that)
{
	data->b_ways[i].ra_rb = ft_max(i, bfr_that);
	data->b_ways[i].rra_rrb =\
			-ft_min(data->a_moves[bfr_that], data->b_moves[i]);
	data->b_ways[i].ra_rrb = bfr_that - data->b_moves[i];
	data->b_ways[i].rra_rb = i - data->a_moves[bfr_that];
}

int	find_bfr_that(t_data *data, int i)
{
	int	j;
	int	min;
	int	max;
	int	bfr_that;

	find_min_and_max(data, &min, &max);
	bfr_that = 0;
	if (data->second_array[i] > data->array[max]
		|| data->second_array[i] < data->array[min])
		return (min);
	j = 0;
	while (j < data->size)
	{
		if (j == data->size - 1)
		{
			if (data->second_array[i] > data->array[j]
				&& data->second_array[i] < data->array[0])
				bfr_that = 0;
		}
		else if (data->second_array[i] > data->array[j]
			&& data->second_array[i] < data->array[j + 1])
			bfr_that = j + 1;
		j++;
	}
	return (bfr_that);
}

void	count_ways(t_data *data)
{
	int	i;
	int	bfr_that;

	i = 0;
	while (i < data->size2)
	{
		bfr_that = find_bfr_that(data, i);
		count_struct_of_ways(data, i, bfr_that);
		i++;
	}
}

void	count_moves(t_data *data)
{
	int	i;

	data->a_moves[0] = 0;
	i = 1;
	while (i < data->size)
	{
		data->a_moves[i] = -(data->size - i);
		i++;
	}
	data->b_moves[0] = 0;
	i = 1;
	while (i < data->size2)
	{
		data->b_moves[i] = -(data->size2 - i);
		i++;
	}
	count_ways(data);
}
