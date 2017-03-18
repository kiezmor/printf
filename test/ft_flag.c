/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhordern <lhordern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 11:20:54 by lhordern          #+#    #+#             */
/*   Updated: 2013/12/18 19:49:28 by lhordern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/includes/libft.h"

int			flag_s(va_list ap)
{
	char	*s;

	s = va_arg(ap, char *);
	ft_putstr(s);
	return (ft_strlen(s));
}

int			flag_c(va_list ap)
{
	char	c;

	c = (char)va_arg(ap, int);
	ft_putchar(c);
	return (1);
}

int			flag_d(va_list ap)
{
	char	*d;

	d = ft_itoa(va_arg(ap, int));
	ft_putstr(d);
	return (ft_strlen(d));
}

int			flag_p(va_list ap)
{
	char	*ptr;

	ptr = (char *)va_arg(ap, void *);
	ft_putstr(ptr);
	return (ft_strlen(ptr));
}
