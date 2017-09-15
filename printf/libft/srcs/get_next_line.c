/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:50:55 by vpluchar          #+#    #+#             */
/*   Updated: 2017/03/08 01:18:07 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		**ft_list(int fd, t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp && tmp->content_size != (size_t)fd)
		tmp = tmp->next;
	if (tmp)
		return ((char **)(&(tmp->content)));
	tmp = ft_lstnew(NULL, 0);
	tmp->content_size = (size_t)fd;
	ft_lstadd(list, tmp);
	return ((char **)(&(tmp->content)));
}

static void		ft_line(char *buf, char **line, int i)
{
	char *tmp;

	if (!*line)
		*line = ft_strdup(buf);
	else
	{
		tmp = *line;
		if (tmp)
		{
			*line = ft_strnew(ft_strlen(tmp) + ft_strlen(buf));
			*line = ft_strcpy(*line, tmp);
		}
		else
			*line = ft_strnew(0 + ft_strlen(buf));
		*line = ft_strcat(*line, buf);
		ft_strdel(&tmp);
		if (buf && i == 1)
			ft_strdel(&buf);
	}
}

static int		ft_check_stock(char *buf, char **stock, char **line, int i)
{
	char	*tmp;

	if (!(ft_strchr(buf, CHAR)))
	{
		if (buf)
			ft_line(buf, line, 0);
		return (0);
	}
	while (buf[i] != CHAR && buf[i] != '\0')
		i++;
	if (*line)
	{
		tmp = ft_strsub(buf, 0, i);
		ft_line(tmp, line, 1);
	}
	else
		*line = ft_strsub(buf, 0, i);
	if (buf[i] != '\0')
		*stock = ft_strdup(buf + i + 1);
	return (1);
}

static int		ft_stock(char **stock, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(ft_strchr(*stock, CHAR)))
	{
		*line = ft_strdup(*stock);
		ft_strdel(stock);
		return (0);
	}
	tmp = *stock;
	while (**stock != CHAR)
	{
		(*stock)++;
		i++;
	}
	*line = ft_strsub(tmp, 0, i);
	*stock = ft_strdup(*stock + 1);
	ft_strdel(&tmp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*list = NULL;
	char			**stock;
	char			tmp[BUFF_SIZE + 1];
	int				ret;

	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	*line = NULL;
	stock = ft_list(fd, &list);
	if (*stock && ft_stock(stock, line) == 1)
		return (1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		tmp[ret] = '\0';
		if (ft_check_stock(tmp, stock, line, 0) == 1)
			return (1);
	}
	if (ret < 0)
		return (-1);
	else if (!*line)
		return (0);
	else if (ret == 0 && **line)
		return (1);
	return (ret);
}
