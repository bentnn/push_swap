#include "checker.h"

int	check_s(char **argv, int i, int j)
{
	int	start;

	start = j;
	if (argv[i][j] == '-')
	{
		if (!ft_isdigit(argv[i][j + 1]))
			return (-1);
		j++;
	}
	while (argv[i][j] && argv[i][j] != ' ')
	{
		if (!ft_isdigit(argv[i][j]))
			return (-1);
		j++;
	}
	if (!is_int(&argv[i][start], j - start))
		return (-1);
	return (j - 1);
}

int	check_array(int argc, char **argv)
{
	int	i;
	int	j;
	int	size;

	i = 1;
	size = 0;
	if (ft_strlen(argv[1]) == 2 && argv[1][0] == '-' && argv[1][1] == 'v')
		i++;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] && argv[i][j] != ' ')
			{
				j = check_s(argv, i, j);
				if (j == -1)
					return (-1);
				size++;
			}
			j++;
		}
		i++;
	}
	return (size);
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
	int		size;

	if (argc < 2)
		return (0);
	size = check_array(argc, argv);
	if (size == -1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	if (size == 0)
		return (0);
	data = create_data(size + 1);
	create_array_of_int(data, argc, argv);
	if (!check_duplicates(data))
	{
		checker_error(data);
		return (1);
	}
	work_with_commands(data);
	check_result(data);
	delete_data(data);
	sleep(8);
	return (0);
}
