#ifndef COMMANDS_H
#define COMMANDS_H

#include "checker.h"

void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

void rra_rb(t_data *data, int bfr_that, int pos);
void ra_rb(t_data *data, int bfr_that, int pos);
void rra_rrb(t_data *data, int bfr_that, int pos);
void ra_rrb(t_data *data, int bfr_that, int pos);

#endif
