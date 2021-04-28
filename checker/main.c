#include "checker.h"

int	is_int(const char *str)
{
	long int	nb;
	long int	temp;
	int			i;

	if (ft_strlen(str) < 10)
		return (1);
	if (ft_strlen(str) > 11)
		return (0);
	nb = ft_atoi(str);
	i = (int)ft_strlen(str) - 1;
	if (nb < 0 && str[0] != '-')
		return (0);
	while (i > 0)
	{
		temp = nb % 10;
		if (temp < 0)
			temp *= -1;
		if (str[i] != (temp + '0'))
			return (0);
		nb /= 10;
		i--;
	}
	if (nb > 0 && str[0] != (nb % 10 + '0'))
		return (0);
	return (1);
}

int	check_array(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 1 && argv[i][0] == '-')
			return (0);
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !(j == 0 && argv[i][j] == '-'))
				return (0);
			j++;
		}
		if (!is_int(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->size)
	{
		j = i + 1;
		while (j < data->size)
		{
			if (data->array[i] == data->array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	check_result(t_data *data)
{
	int	i;

	if (data->size2 == 0)
	{
		i = 1;
		while (i < data->size)
		{
			if (data->array[i] < data->array[i - 1])
			{
				ft_putstr("KO\n");
				return ;
			}
			i++;
		}
		ft_putstr("OK\n");
	}
	else
		ft_putstr("KO\n");
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc == 1)
		return (0);
	if (!check_array(argc, argv))
	{
		ft_putstr("Error\n");
		return (1);
	}
	data = create_data(argc);
	create_array_of_int(data, argc, argv);
	if (!check_duplicates(data))
	{
		checker_error(data);
		return (1);
	}
	work_with_commands(data);
	check_result(data);
	delete_data(data);
	return (0);
}
