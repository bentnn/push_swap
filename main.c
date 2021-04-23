#include <stdio.h>
#include "checker.h"

int check_array(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !(j == 0 && argv[i][j] == '-'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void check_result(t_data *data)
{
	int i;

	if (data->size2 == 0)
	{
		i = 1;
		while (i < data->size)
		{
			if (data->array[i] < data->array[i - 1])
			{
				ft_putstr("KO\n");
				return;
			}
			i++;
		}
		ft_putstr("OK\n");
	}
	else
		ft_putstr("KO\n");
}

int main(int argc, char **argv)
{
	t_data *data;
	if (argc == 1)
	{
		ft_putstr("add some numbers, idiot\n");
		return (-1);
	}
	if (!check_array(argc, argv))
	{
		ft_putstr("i need only integer!\n");
		return (-1);
	}
	data = create_data(argc);
	create_array_of_int(data, argc, argv);
	output_stacks(data);
	work_with_commands(data);
	check_result(data);
	delete_data(data);
}
