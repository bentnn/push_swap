#include "push_swap.h"
#include "swap_commands_ps.h"

static int	find_min_nb(t_data *data)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (i < data->size)
	{
		if (data->array[i] < data->array[min])
			min = i;
		i++;
	}
	return (min);
}

void	put_in_place(t_data *data)
{
	int	min;

	min = find_min_nb(data);
	if (data->size - min > min)
	{
		while (min > 0)
		{
			ra(data);
			ft_putstr("ra\n");
			min--;
		}
	}
	else
	{
		min = data->size - min;
		while (min > 0)
		{
			rra(data);
			ft_putstr("rra\n");
			min--;
		}
	}
}

int	is_sorted(t_data *data)
{
	int	i;

	if (data->size2 != 0)
		return (0);
	i = 0;
	while (i < data->size - 1)
	{
		if (data->array[i] > data->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	big_sort(t_data *data)
{
	int	min;
	int	pos;
	int	bfr_that;

	while (data->size2 != 0)
	{
		count_moves(data);
		min = find_min_way(data, &pos);
		bfr_that = find_bfr_that(data, pos);
		if (data->b_ways[pos].ra_rb == min)
			ra_rb(data, bfr_that, pos);
		else if (data->b_ways[pos].rra_rrb == min)
			rra_rrb(data, bfr_that, pos);
		else if (data->b_ways[pos].ra_rrb == min)
			ra_rrb(data, bfr_that, pos);
		else
			rra_rb(data, bfr_that, pos);
	}
	if (!is_sorted(data))
		put_in_place(data);
}

void	push_swap(t_data *data)
{
	if (is_sorted(data) || data->size == 1)
		return ;
	if (data->size == 2)
	{
		if (data->array[0] > data->array[1])
		{
			sa(data);
			ft_strlen("sa\n");
		}
		return ;
	}
	while (data->size != 3)
	{
		pb(data);
		ft_putstr("pb\n");
	}
	sort_three(data);
	if (data->size2 != 0)
		big_sort(data);
}
