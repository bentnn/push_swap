#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

typedef struct s_data
{
	int		*array;
	int		*second_array;
	int		size;
	int		size2;
	int		bonus;
}				t_data;

void	create_array_of_int(t_data *data, int argc, char **argv);
t_data	*create_data(int argc);
void	delete_data(t_data *data);
void	output_stacks(t_data *data);
void	work_with_commands(t_data *data);
void	checker_error(t_data *data);
int		len_of_nb(int nb);
void	find_command(t_data *data, char *line);
int		is_int(const char *str, int len);

#endif
