#include "checker.h"
#include "swap_commands.h"

void checker_error(t_data *data)
{
	delete_data(data);
	ft_putstr("ERROR!!!\n");
	exit(1);
}

void find_command(t_data *data, char *line)
{
	if (line[0] == 's' && ft_strlen(line) == 2)
	{
		if (line[1] == 'a')
			sa(data);
		else if (line[1] == 'b')
			sb(data);
		else if (line[1] == 's')
			ss(data);
		else
			checker_error(data);
	}
	else if (line[0] == 'p' && ft_strlen(line) == 2)
	{
		if (line[1] == 'a')
			pa(data);
		else if (line[1] == 'b')
			pb(data);
		else
			checker_error(data);
	}
	else if (line[0] == 'r' && ft_strlen(line) == 2)
	{
		if (line[1] == 'a')
			ra(data);
		else if (line[1] == 'b')
			rb(data);
		else if (line[1] == 'r')
			rr(data);
		else
			checker_error(data);
	}
	else if (line[0] == 'r' && line[1] == 'r' && ft_strlen(line) == 3)
	{
		if (line[2] == 'a')
			rra(data);
		else if(line[2] == 'b')
			rrb(data);
		else if (line[2] == 'r')
			rrr(data);
		else
			checker_error(data);
	}
	else
		checker_error(data);
}

void work_with_commands(t_data *data)
{
	int res;
	char *line;

	while (1)
	{
		res = get_next_line(1, &line);
		if (res == -1)
		{
			if (line)
				free(line);
			checker_error(data);
			return;
		}
		if (res != 0 && ft_strlen(line) != 0)
		{
			find_command(data, line);
			output_stacks(data);
		}
		if (res == 0 || ft_strlen(line) == 0)
		{
			free(line);
			ft_strlen("end\n");
			return;
		}
		free(line);
	}
}