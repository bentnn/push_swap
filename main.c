#include <stdio.h>
#include "checker.h"
#include "commands/commands.h"

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
	int i = 0;
	sa(data);
	output_stacks(data);
//	while (i < data->size)
//	{
//		printf("%d\n", data->array[i]);
//		i++;
//	}
	delete_data(data);
}
