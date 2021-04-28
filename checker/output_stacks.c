#include "checker.h"v

int	find_max_len(int *array, int size)
{
	int	max;
	int	i;
	int	new;

	if (size == 0)
		return (1);
	max = 0;
	i = 0;
	while (i < size)
	{
		new = len_of_nb(array[i]);
		if (new > max)
			max = new;
		i++;
	}
	return (max);
}

void	put_spases(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(' ');
		i++;
	}
}

void	end_output_line(int max_len1, int max_len2)
{
	int	i;

	i = 0;
	while (i < max_len1)
	{
		ft_putchar('-');
		i++;
	}
	ft_putchar(' ');
	i = 0;
	while (i < max_len2)
	{
		ft_putchar('-');
		i++;
	}
	ft_putstr("\na");
	put_spases(max_len1);
	ft_putstr("b\n");
}

int	output_nb(t_data *data, int nb)
{
	char	*str;
	int		len;

	str = ft_itoa(nb);
	if (!str)
		checker_error(data);
	len = (int)ft_strlen(str);
	ft_putstr(str);
	free(str);
	return (len);
}

void	output_stacks(t_data *data)
{
	int		max;
	int		i;
	int		max_len1;
	int		max_len2;

	max = ft_max(data->size, data->size2);
	max_len1 = find_max_len(data->array, data->size);
	max_len2 = find_max_len(data->second_array, data->size2);
	i = 0;
	while (i < max)
	{
		if (i < data->size)
			put_spases(max_len1 - output_nb(data, data->array[i]) + 1);
		else
			put_spases(max_len1 + 1);
		if (i < data->size2)
			output_nb(data, data->second_array[i]);
		ft_putchar('\n');
		i++;
	}
	end_output_line(max_len1, max_len2);
}
