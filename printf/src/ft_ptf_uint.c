/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 12:24:58 by vpluchar          #+#    #+#             */
/*   Updated: 2017/08/23 12:24:58 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static unsigned long long	get_arg(va_list arg, int flags)
{
	if (flags == 'L')
		return (va_arg(arg, unsigned long long));
	else if (flags == 'j')
		return (va_arg(arg, uintmax_t));
	else if (flags == 'z')
		return (va_arg(arg, ssize_t));
	else if (flags == 'l')
		return (va_arg(arg, unsigned long int));
	else if (flags == 'h')
		return ((unsigned short)va_arg(arg, unsigned int));
	else if (flags == 'H')
		return ((unsigned char)va_arg(arg, unsigned int));
	else
		return (va_arg(arg, unsigned int));
}

static int					get_base(char c)
{
	if (c == 'x' || c == 'X')
		return (16);
	if (c == 'o')
		return (8);
	return (10);
}

static void					u_rules(t_flags *flags)
{
	if (flags->setting)
	{
		if (flags->FLAGS_ZERO && flags->FLAGS_DASH)
			flags->FLAGS_ZERO = 0;
		if (flags->precision != -1)
			flags->FLAGS_ZERO = 0;
	}
}

static void					u_write(unsigned long long n, t_flags *f)
{
	char	*sign;
	int		size;

	sign = NULL;
	if (n)
	{
		if (f->conversion == 'x' && f->FLAGS_HASH)
			sign = "0x";
		else if (f->conversion == 'X' && f->FLAGS_HASH)
			sign = "0X";
		else if (f->conversion == 'o' && f->FLAGS_HASH)
		{
			size = ft_ptf_tmp(NULL, 0, GET);
			if (f->precision <= size)
				sign = "0";
		}
	}
	ft_ptf_join(f, sign);
}

int							ft_ptf_uint(va_list arg)
{
	unsigned long long	nbr;
	t_flags		*flags;
	int					base;

	flags = get_ptf_flags(GET_FLAGS);
	nbr = get_arg(arg, flags->length);
	base = get_base(flags->conversion);
	ft_ptf_putnbr(nbr, base, flags->conversion);
	u_rules(flags);
	u_write(nbr, flags);
	return (0);
}
