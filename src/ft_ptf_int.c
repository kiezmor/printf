/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 12:21:31 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/18 21:13:13 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long			get_arg(va_list arg, int flags)
{
	if (flags == 'l')
		return (va_arg(arg, long));
	else if (flags == 'L')
		return (va_arg(arg, long long));
	else if (flags == 'z')
		return (va_arg(arg, size_t));
	else if (flags == 'j')
		return (va_arg(arg, intmax_t));
	else if (flags == 'h')
		return ((short)va_arg(arg, int));
	else if (flags == 'H')
		return ((char)va_arg(arg, int));
	else
		return (va_arg(arg, int));
}

static unsigned long long	get_nbr(long long num)
{
	unsigned long long	nbr;

	if (num < 0)
		nbr = -num;
	else
		nbr = num;
	return (nbr);
}

static void					int_rules(t_flags *flags)
{
	if (flags->setting)
	{
		if (flags->FLAGS_ZERO && flags->FLAGS_DASH)
			flags->FLAGS_ZERO = 0;
		if (flags->precision != -1)
			flags->FLAGS_ZERO = 0;
	}
}

static void					write_int(long long nb, t_flags *flags)
{
	char	*sign;

	sign = NULL;
	if (nb < 0)
		sign = "-";
	else if (flags->FLAGS_PLUS)
		sign = "+";
	else if (flags->FLAGS_SPACE)
		sign = " ";
	ft_ptf_join(flags, sign);
}

int							ft_ptf_int(va_list arg)
{
	t_flags			*flags;
	long long		nbr;

	flags = ft_g_flags(GET_FLAGS);
	nbr = get_arg(arg, flags->length);
	ft_ptf_putnbr(get_nbr(nbr), 10, flags->conversion);
	int_rules(flags);
	write_int(nbr, flags);
	return (0);
}
