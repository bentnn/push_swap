#include "checker.h"
#include "swap_commands.h"

static void	s_commands(t_data *data, const char *line)
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

static void	p_commands(t_data *data, const char *line)
{
	if (line[1] == 'a')
		pa(data);
	else if (line[1] == 'b')
		pb(data);
	else
		checker_error(data);
}

static void	r_commands(t_data *data, const char *line)
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

static void	rr_commands(t_data *data, const char *line)
{
	if (line[2] == 'a')
		rra(data);
	else if (line[2] == 'b')
		rrb(data);
	else if (line[2] == 'r')
		rrr(data);
	else
		checker_error(data);
}

void	find_command(t_data *data, char *line)
{
	if (line[0] == 's' && ft_strlen(line) == 2)
		s_commands(data, line);
	else if (line[0] == 'p' && ft_strlen(line) == 2)
		p_commands(data, line);
	else if (line[0] == 'r' && ft_strlen(line) == 2)
		r_commands(data, line);
	else if (line[0] == 'r' && line[1] == 'r' && ft_strlen(line) == 3)
		rr_commands(data, line);
	else
		checker_error(data);
}
