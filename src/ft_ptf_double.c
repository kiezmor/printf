/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 16:14:45 by vpluchar          #+#    #+#             */
/*   Updated: 2017/09/15 16:14:45 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		is_denormalized(int e, int m)
{
	if (e == 0 && m != 0)
		return (1);
	else if ((e == 0x000007FF) && m == 0)
		return (2);
	else if ((e == 0x000007FF) && m != 0)
		return (3);
	return (0);
}

static double	get_mantisse(long long m)
{
	double		ret;
	int			j;
	long long	i;
	long long	bit;

	i = 51;
	j = -1;
	ret = 0.0;
	while (i >= 0)
	{
		bit = (m & (1ll << i)) ? 1 : 0;
		ret += (bit) ? ft_ptf_pow(2, j) : 0;
		j--;
		i--;
	}
	return (ret);
}

static double	get_value(long long s, long long e, long long m)
{
	double		ret;
	double		mantisse;
	long long	sign;
	int			c;

	ret = 0.0;
	mantisse = get_mantisse(m);
	sign = (s) ? -1 : 1;
	c = is_denormalized(e, m);
	if (c == 1)
		ret = sign * ft_ptf_pow(2, e - 1022) * mantisse;
	if (c == 0)
		ret = sign * ft_ptf_pow(2, e - 1023) * (1ll + mantisse);
	if (c == 2)
		return (ft_ptf_tmp("inf", -1, SET));
	if (c == 3)
		return (ft_ptf_tmp("nan", -1, SET));
	return (ret);
}

static void		double_output(double f, int size, char conversion)
{
	if (conversion == 'f')
		ft_ptf_putdouble(f, size);
	else if (conversion == 'e')
		ft_ptf_double_sc(f, size);
}

int				ft_ptf_double(double f, int size, char conversion)
{
	long long	nb;
	long long	s;
	long long	e;
	long long	m;

	double_output(f, size, conversion);
	nb = *(long long *)&f;
	s = (nb >> 63);
	e = ((nb & 0x7FF0000000000000) >> 52);
	m = (nb & 0x000FFFFFFFFFFFFF);
	f = get_value(s, e, m);
	return (1);
}
