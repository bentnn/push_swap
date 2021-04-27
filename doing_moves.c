#include "checker.h"
#include "swap_commands.h"

void rra_rb(t_data *data, int bfr_that, int pos)
{
	bfr_that = data->array[bfr_that];
	pos = data->second_array[pos];
	while (data->array[0] != bfr_that)
	{
		rra(data);
		ft_putstr("rra\n");
	}
	while (data->second_array[0] != pos)
	{
		rb(data);
		ft_putstr("rb\n");
	}
	pa(data);
	ft_putstr("pa\n");
}

void ra_rb(t_data *data, int bfr_that, int pos)
{
	bfr_that = data->array[bfr_that];
	pos = data->second_array[pos];
	while (data->array[0] != bfr_that && data->second_array[0] != pos)
	{
		rr(data);
		ft_putstr("rr\n");
	}
	while (data->array[0] != bfr_that)
	{
		ra(data);
		ft_putstr("ra\n");
	}
	while (data->second_array[0] != pos)
	{
		rb(data);
		ft_putstr("rb\n");
	}
	pa(data);
	ft_putstr("pa\n");
}

void rra_rrb(t_data *data, int bfr_that, int pos)
{
	bfr_that = data->array[bfr_that];
	pos = data->second_array[pos];
	while (data->array[0] != bfr_that && data->second_array[0] != pos)
	{
		rrr(data);
		ft_putstr("rrr\n");
	}
	while (data->array[0] != bfr_that)
	{
		rra(data);
		ft_putstr("rra\n");
	}
	while (data->second_array[0] != pos)
	{
		rrb(data);
		ft_putstr("rrb\n");
	}
	pa(data);
	ft_putstr("pa\n");
}

void ra_rrb(t_data *data, int bfr_that, int pos)
{
	bfr_that = data->array[bfr_that];
	pos = data->second_array[pos];
	while (data->array[0] != bfr_that)
	{
		ra(data);
		ft_putstr("ra\n");
	}
	while (data->second_array[0] != pos)
	{
		rrb(data);
		ft_putstr("rrb\n");
	}
	pa(data);
	ft_putstr("pa\n");
}