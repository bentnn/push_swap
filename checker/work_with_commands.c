#include "checker.h"

void	checker_error(t_data *data)
{
	delete_data(data);
	ft_putstr("Error\n");
	exit(1);
}

void	work_with_commands(t_data *data)
{
	int		res;
	char	*line;

	while (1)
	{
		res = get_next_line(1, &line);
		if (res == -1)
		{
			checker_error(data);
			return ;
		}
		if (res != 0 && ft_strlen(line) != 0)
		{
			find_command(data, line);
			output_stacks(data);
		}
		if (res == 0 || ft_strlen(line) == 0)
		{
			free(line);
			return ;
		}
		free(line);
	}
}
