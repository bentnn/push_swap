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

static void push_from_to(int *array1, int *array2, int size1, int size2)
{
	int i;
	int nb;

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

static void	rotate(int *array, int size)
{
	int	i;
	int nb;

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