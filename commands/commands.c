#include "commands.h"

void sa(t_data *data)
{
	if (data->size >= 2)
	{
		data->array[0] += data->array[1];
		data->array[1] -= data->array[0] - data->array[1];
		data->array[0] -= data->array[1];
	}
}