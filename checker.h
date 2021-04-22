#ifndef CHECKER_H
#define CHECKER_H

#include "libft/libft.h"

typedef struct s_data
{
	int *array;
	int size;
}				t_data;

void create_array_of_int(t_data *data, int argc, char **argv);
t_data *create_data(int argc);
void delete_data(t_data *data);


#endif