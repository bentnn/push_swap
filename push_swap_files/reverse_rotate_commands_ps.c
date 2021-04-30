#include "swap_commands_ps.h"

static void	reverse_rotate(int *array, int size)
{
	int	i;
	int	nb;

	nb = array[size - 1];
	i = size - 1;
	while (i > 0)
	{
		array[i] = array[i - 1];
		i--;
	}
	array[0] = nb;
}

void	rra(t_data *data)
{
	if (data->size > 1)
	{
		reverse_rotate(data->array, data->size);
	}
}

void	rrb(t_data *data)
{
	if (data->size2 > 1)
	{
		reverse_rotate(data->second_array, data->size2);
	}
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}
