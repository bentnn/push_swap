#include "swap_commands.h"
#include "checker.h"

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
	}
}

void push_swap(t_data *data)
{
	if (data->size == 2)
	{
		if (data->array[0] > data->array[1])
		{
			sa(data);
			ft_strlen("sa\n");
		}
		return ;
	}
	if (data->size == 3)
	{
		sort_three(data);
		return ;
	}
}