/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 05:05:34 by vpluchar          #+#    #+#             */
/*   Updated: 2017/03/19 05:05:36 by vpluchar         ###   ########.fr       */
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
