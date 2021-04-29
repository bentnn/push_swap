#include "swap_commands_ps.h"
#include "push_swap.h"

static void	push_from_to(int *array1, int *array2, int size1, int size2)
{
	int	i;
	int	nb;

	i = 0;
	nb = array1[0];
	while (i < size1 - 1)
	{
		array1[i] = array1[i + 1];
		i++;
	}
	i = size2 + 1;
	while (i > 0)
	{
		array2[i] = array2[i - 1];
		i--;
	}
	array2[0] = nb;
}

void	pa(t_data *data)
{
	if (data->size2 >= 1)
	{
		push_from_to(data->second_array, data->array, data->size2, data->size);
		data->size2--;
		data->size++;
	}
}

void	pb(t_data *data)
{
	if (data->size >= 1)
	{
		push_from_to(data->array, data->second_array, data->size, data->size2);
		data->size--;
		data->size2++;
	}
}
