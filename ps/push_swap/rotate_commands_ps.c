#include "swap_commands_ps.h"

static void	rotate(int *array, int size)
{
	int	i;
	int	nb;

	nb = array[0];
	i = 0;
	while (i < size - 1)
	{
		array[i] = array[i + 1];
		i++;
	}
	array[i] = nb;
}

void	ra(t_data *data)
{
	if (data->size > 1)
		rotate(data->array, data->size);
}

void	rb(t_data *data)
{
	if (data->size2 > 1)
		rotate(data->second_array, data->size2);
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
