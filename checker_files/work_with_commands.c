#include "checker.h"

int	is_int(const char *str, int len)
{
	long int	nb;
	long int	temp;
	int			i;

	if (len < 10)
		return (1);
	if (len > 11)
		return (0);
	nb = ft_atoi(str);
	i = len - 1;
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

void	checker_error(t_data *data)
{
	delete_data(data);
	ft_putstr("Error\n");
	get_next_line(-1, 0);
	exit(1);
}

void	output_start(t_data *data)
{
	ft_putstr("\033[1;36m");
	ft_putstr("Start:\n");
	ft_putstr("\033[0m");
	output_stacks(data);
	ft_putstr("\n");
}

void	output_bonus(t_data *data, const char *line)
{
	ft_putstr("\033[1;36m");
	ft_putstr(line);
	ft_putstr(":\n");
	ft_putstr("\033[0m");
	output_stacks(data);
	ft_putstr("\n");
}

void	work_with_commands(t_data *data)
{
	int		res;
	char	*line;

	if (data->bonus == 1)
		output_start(data);
	while (1)
	{
		res = get_next_line(0, &line);
		if (res == -1)
		{
			checker_error(data);
			return ;
		}
		if (res != 0)
		{
			find_command(data, line);
			if (data->bonus == 1)
				output_bonus(data, line);
		}
		free(line);
		if (res == 0)
			return ;
	}
}
