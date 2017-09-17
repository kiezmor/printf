/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ptf_lw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 02:50:12 by vpluchar          #+#    #+#             */
/*   Updated: 2017/09/15 02:50:12 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int  is_long(char c)
{
    if (c == 'h' || c == 'H' || c == '0')
        return (0);
    else
        return (1);
}

static int  keep_length(char c, t_flags *flags)
{
    if (is_long(flags->length) && (c == 'h' || c == 'H'))
        return (flags->length);
    else
        return (c);
}

static int  set_length(char c, t_flags *flags)
{
    flags->length = keep_length(c, flags);
    flags->setting = 1;
    if (c == 'L' || c == 'H')
        return (2);
    else
        return (1);
}

int set_ptf_length(char *arg, t_flags *flags)
{
    if (arg[0] == 'l' || arg[0] == 'h')
    {
        if(arg[1] == 'l' && arg[0] == 'l')
            return (set_length('L', flags));
        if (arg[1] == 'h' && arg[0] == 'h')
            return (set_length('H', flags));
        return (set_length(arg[0], flags));
    }
    else if (arg[0] == 'j' || arg[0] == 'z')
        return (set_length(arg[0], flags));
    else
        return (0);
}

int	set_ptf_width(char *arg, va_list args, t_flags *flags)
{
	char	*tmp;
	int	nbr;

	tmp = arg;
	if(*tmp == '*' || (*tmp >= '0' && *tmp <= '9'))
	{
		if (*tmp == '*' && arg++)
		{
			nbr = va_arg(args, int);
			if (nbr < 0)
			{
				nbr = -nbr;
				flags->FLAGS_DASH = 1;
			}
			flags->width = nbr;
		}
		else
			flags->width = ft_ptf_atoi(&arg);
		if (flags->width)
			flags->setting = 1;
	}
	return (arg - tmp);
}
