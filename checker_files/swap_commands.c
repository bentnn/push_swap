#include "swap_commands.h"

static void	swap_2_elems(int *array)
{
	array[0] += array[1];
	array[1] = array[0] - array[1];
	array[0] -= array[1];
}

void	sa(t_data *data)
{
	if (data->size >= 2)
		swap_2_elems(data->array);
}

void	sb(t_data *data)
{
	if (data->size2 >= 2)
		swap_2_elems(data->second_array);
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}
