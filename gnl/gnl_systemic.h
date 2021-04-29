/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_systemic.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabet <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 20:33:18 by aabet             #+#    #+#             */
/*   Updated: 2021/03/18 20:33:20 by aabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_SYSTEMIC_H
# define GNL_SYSTEMIC_H

# include <unistd.h>
# include <stdlib.h>

int	gnl_strlen(const char *str);
int	return_error(char *str1, char *str2);
int	gnl_strchr(const char *str, int c);
int	end_of_gnl(char *new, char **line);
int	ret_and_free(char *str, int res);
int	read_and_ret_res(int fd, char *buf, int *res);
int	check_res_and_set_buf(int res, char *buf);

#endif
