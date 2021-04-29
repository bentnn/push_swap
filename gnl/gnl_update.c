#include "gnl_systemic.h"
#include "get_next_line.h"

int	end_of_gnl(char *new, char **line)
{
	if (!new)
	{
		new = malloc(sizeof(char));
		if (!new)
			return (-1);
		new[0] = '\0';
	}
	*line = new;
	return (0);
}

int	ret_and_free(char *str, int res)
{
	free(str);
	return (res);
}

int	read_and_ret_res(int fd, char *buf, int *res)
{
	*res = (int)read(fd, buf, BUFFER_SIZE);
	return (*res);
}

int	check_res_and_set_buf(int res, char *buf)
{
	if (res == -1)
		return (res);
	buf[res] = '\0';
	return (1);
}
