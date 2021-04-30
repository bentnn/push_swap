#include "push_swap.h"
#include "swap_commands_ps.h"

int	cmp_ways(t_data *data, int i, int min, int *position)
{
	if (data->b_ways[i].rra_rb < min)
	{
		min = data->b_ways[i].rra_rb;
		*position = i;
	}
	if (data->b_ways[i].rra_rrb < min)
	{
		min = data->b_ways[i].rra_rrb;
		*position = i;
	}
	if (data->b_ways[i].ra_rb < min)
	{
		min = data->b_ways[i].ra_rb;
		*position = i;
	}
	if (data->b_ways[i].ra_rrb < min)
	{
		min = data->b_ways[i].ra_rrb;
		*position = i;
	}
	return (min);
}

int	find_min_way(t_data *data, int *pos)
{
	int	min;
	int	i;
	int	position;

	min = INT32_MAX;
	i = 0;
	position = 0;
	while (i < data->size2)
	{
		min = cmp_ways(data, i, min, &position);
		i++;
	}
	*pos = position;
	return (min);
}

static void	sort_321(t_data *data)
{
	sa(data);
	rra(data);
	ft_putstr("sa\nrra\n");
}

void	sort_three(t_data *data)
{
	if (data->array[0] < data->array[2] && data->array[1] > data->array[2])
	{
		rra(data);
		sa(data);
		ft_putstr("rra\nsa\n");
	}
	else if (data->array[1] < data->array[0] && data->array[0] < data->array[2])
	{
		sa(data);
		ft_putstr("sa\n");
	}
	else if (data->array[2] < data->array[0] && data->array[0] < data->array[1])
	{
		rra(data);
		ft_putstr("rra\n");
	}
	else if (data->array[2] > data->array[1] && data->array[0] > data->array[2])
	{
		ra(data);
		ft_putstr("ra\n");
	}
	else if (data->array[1] > data->array[2] && data->array[0] > data->array[1])
		sort_321(data);
}
