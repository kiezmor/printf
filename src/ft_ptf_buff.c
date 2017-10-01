/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 12:56:07 by vpluchar          #+#    #+#             */
/*   Updated: 2017/08/21 12:56:07 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	read_buff(char *buffer, int *i)
{
	int	size;
	int	fd;

	fd = ft_ptf_fd(0, GET);
	size = *i;
	write(fd, buffer, size);
	*i = 0;
}

static int	write_str(char *buf, int *size, char *str)
{
	int	i;
	int	j;

	if (!str)
		return (0);
	i = 0;
	j = *size;
	while (str[i])
	{
		if (j == BUF_SIZE)
			read_buff(buf, &j);
		buf[j++] = str[i++];
	}
	buf[j] = 0;
	*size = j;
	return (i);
}

static int	write_char(char *buf, int *size, int c)
{
	int	j;

	j = *size;
	if (j == BUF_SIZE)
		read_buff(buf, &j);
	buf[j++] = c;
	*size = j;
	return (1);
}

int			ft_ptf_buff(char *str, int act)
{
	static char		buf[BUF_SIZE + 1];
	static int		size = 0;
	static int		total = 0;
	int				i;

	i = total;
	if (act == BUF_CHAR)
		total += write_char(buf, &size, *str);
	else if (act == BUF_WRITE)
		total += write_str(buf, &size, str);
	else if (act == BUF_READ)
	{
		read_buff(buf, &size);
		i = total;
		total = 0;
	}
	return (i);
}
