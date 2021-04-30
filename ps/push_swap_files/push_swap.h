#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_ways
{
	int	ra_rb;
	int	ra_rrb;
	int	rra_rrb;
	int	rra_rb;
}				t_ways;

typedef struct s_data
{
	int		*array;
	int		*second_array;
	int		size;
	int		size2;
	int		*a_moves;
	int		*b_moves;
	t_ways	*b_ways;
}				t_data;

t_data	*create_data(int argc);
void	delete_data(t_data *data);
void	create_array_of_int(t_data *data, int argc, char **argv);
void	ps_error(t_data *data);
void	push_swap(t_data *data);
int		is_sorted(t_data *data);
int		find_bfr_that(t_data *data, int i);
void	find_min_and_max(t_data *data, int *min, int *max);
void	count_moves(t_data *data);
int		find_min_way(t_data *data, int *pos);
void	sort_three(t_data *data);

#endif
