/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhordern <lhordern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 12:52:28 by lhordern          #+#    #+#             */
/*   Updated: 2013/12/18 19:50:32 by lhordern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/includes/libft.h"

t_flag	flag_tab[NB_FLAG] =
{
	{'c', &flag_c},
	{'d', &flag_d},
	{'p', &flag_p},
	{'s', &flag_s},
};

int			ft_printf(const char *format, ...)
{
	int		i;
	va_list		args;
	int		comp;

	i = 0;
	comp = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i])
		{
			i++;
			comp += ft_checkflag(format[i], args);
		}
		else
		{
			ft_putchar(format[i]);
			comp++;
		}
		i++;
	}
	va_end(args);
	return (comp);
}

int			ft_checkflag(char flag, va_list args)
{
	int	i;
	char	*st_flag;

	st_flag = ft_strnew(1);
	st_flag[0] = flag;
	i = 0;
	if (flag == '%')
	{
		ft_putchar (flag);
		return (1);
	}
	while (i < NB_FLAG)
	{
		if (ft_strcmp(st_flag, &flag_tab[i].key) == 0)
			return (flag_tab[i].ptrfunc(args));
		i++;
	}
	ft_putstr("Unknown command: %");
	ft_putendl(st_flag);
	return (0);
}
