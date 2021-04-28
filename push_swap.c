#include "checker/swap_commands.h"
#include "checker/checker.h"

void find_min_and_max(t_data *data, int *min, int *max)
{
	int mn;
	int mx;
	int i;

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

void count_struct_of_ways(t_data *data, int i, int bfr_that)
{
	data->b_ways[i].ra_rb = ft_max(i, bfr_that);
	data->b_ways[i].rra_rrb = -ft_min(data->a_moves[bfr_that], data->b_moves[i]);
	data->b_ways[i].ra_rrb = bfr_that - data->b_moves[i];
	data->b_ways[i].rra_rb = i - data->a_moves[bfr_that];
}

int find_bfr_that(t_data *data, int i)
{
	int j;
	int min;
	int max;
	int bfr_that;

	find_min_and_max(data, &min, &max);
	bfr_that = 0;

	if (data->second_array[i] > data->array[max]
		|| data->second_array[i] < data->array[min])
		bfr_that = min;
	else
	{
		j = 0;
		while (j < data->size)
		{
			if (j == data->size - 1)
			{
				if (data->second_array[i] > data->array[j] && data->second_array[i] < data->array[0])
					bfr_that = 0;
			}
			else if (data->second_array[i] > data->array[j] && data->second_array[i] < data->array[j + 1])
				bfr_that = j + 1;
			j++;
		}
	}
	return (bfr_that);
}

void	count_ways(t_data *data)
{
	int i;
	int bfr_that;

	i = 0;
	while (i < data->size2)
	{
		bfr_that = find_bfr_that(data, i);
		count_struct_of_ways(data, i, bfr_that);
		i++;
	}

}

void count_moves(t_data *data)
{
	int i;

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

int find_min_way(t_data *data, int *pos)
{
	int min;
	int i;
	int position;

	min = INT32_MAX;
	i = 0;
	position = 0;
	while (i < data->size2)
	{
		if (data->b_ways[i].rra_rb < min)
		{
			min = data->b_ways[i].rra_rb;
			position = i;
		}
		if (data->b_ways[i].rra_rrb < min)
		{
			min = data->b_ways[i].rra_rrb;
			position = i;
		}
		if (data->b_ways[i].ra_rb < min)
		{
			min = data->b_ways[i].ra_rb;
			position = i;
		}
		if (data->b_ways[i].ra_rrb < min)
		{
			min = data->b_ways[i].ra_rrb;
			position = i;
		}
		i++;
	}
	*pos = position;
	return (min);
}

void put_in_place(t_data *data)
{
	int i;
	int min;

	min = 0;
	i = 0;
	while (i < data->size)
	{
		if (data->array[i] < data->array[min])
			min = i;
		i++;
	}
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

int is_sorted(t_data *data)
{
	int i;

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

#include <stdio.h>
void	big_sort(t_data *data)
{
//	count_moves(data);
	int i;
//	i = 0;
//	while (i < data->size2)
//	{
//		printf("%d:\nra_rb = %d\nrra_rrb = %d\nra_rrb = %d\nrra_rb = %d\n", data->second_array[i], data->b_ways[i].ra_rb, data->b_ways[i].rra_rrb,
//			   data->b_ways[i].ra_rrb, data->b_ways[i].rra_rb);
//		i++;
//	}
//	int min;
//	int pos;
//	min = find_min_way(data, &pos);
//	printf("min = %d, pos = %d\n", min, pos);
	int min;
	int pos;
	int bfr_that;

	while (data->size2 != 0)
	{
		count_moves(data);
		min = find_min_way(data, &pos);
		bfr_that = find_bfr_that(data, pos);
//		if (data->b_ways[pos].rra_rb == min)
//			rra_rb(data, bfr_that, pos);
//		else if (data->b_ways[pos].ra_rrb == min)
//			ra_rrb(data, bfr_that, pos);
//		else if (data->b_ways[pos].ra_rb == min)
//			ra_rb(data, bfr_that, pos);
//		else
//			rra_rrb(data, bfr_that, pos);

//	i = 0;
//	while (i < data->size2)
//	{
//		printf("%d:\nra_rb = %d\nrra_rrb = %d\nra_rrb = %d\nrra_rb = %d\n", data->second_array[i], data->b_ways[i].ra_rb, data->b_ways[i].rra_rrb,
//			   data->b_ways[i].ra_rrb, data->b_ways[i].rra_rb);
//		i++;
//	}
//	printf("min = %d, pos = %d, bfr_that = %d\n", min, pos, bfr_that);


		if (data->b_ways[pos].ra_rb == min)
			ra_rb(data, bfr_that, pos);
		else if (data->b_ways[pos].rra_rrb == min)
			rra_rrb(data, bfr_that, pos);
		else if (data->b_ways[pos].ra_rrb == min)
			ra_rrb(data, bfr_that, pos);
		else
			rra_rb(data, bfr_that, pos);
//		output_stacks(data);
	}
	if (!is_sorted(data))
		put_in_place(data);
}

void sort_three(t_data *data)
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
	{
		sa(data);
		rra(data);
		ft_putstr("sa\nrra\n");
	}
}

void push_swap(t_data *data)
{
	if (is_sorted(data))
		return ;
	if (data->size == 1)
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
//		if (data->size2 > 1 && data->second_array[0] > data->second_array[1])
//		{
//			sb(data);
//			ft_putstr("sb\n");
//		}
	}
//	output_stacks(data);

	sort_three(data);
//	output_stacks(data);

	if (data->size2 != 0)
		big_sort(data);
}