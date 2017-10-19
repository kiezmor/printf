/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 16:36:14 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/18 21:08:18 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned long long	cplt2(long long a)
{
	unsigned long long ret;

	if (a < 0)
	{
		ret = 0xFFFFFFFFFFFFFFFF - a;
		ret--;
	}
	else
		ret = a;
	return (ret);
}

static	void				bin(unsigned long long nb, int size)
{
	char		tab[size + 1];
	int			i;

	i = 0;
	tab[size] = 0;
	while (i < size)
	{
		tab[(size - 1) - i] = (nb % 2) + '0';
		nb /= 2;
		i++;
	}
	ft_ptf_tmp(tab, -1, SET);
}

int							ft_ptf_bin(va_list ap)
{
	t_flags			*flags;
	int				size;
	long long		nb;

	flags = ft_g_flags(GET_FLAGS);
	size = 16;
	nb = va_arg(ap, long long);
	if (flags->setting)
		size = (flags->precision < 0) ? 16 : flags->precision;
	size = (size > 64) ? 64 : size;
	bin(cplt2(nb), size);
	ft_ptf_join(flags, NULL);
	return (0);
}
