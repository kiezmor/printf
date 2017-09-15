/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ptf_cfp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 02:50:00 by vpluchar          #+#    #+#             */
/*   Updated: 2017/09/15 02:50:00 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int set_ptf_conversion(char *arg, t_flags *flags)
{
    if (!*arg)
        return (0);
    flags->conversion = *arg;
    return (1);
}

static int  set_flags(int tab, t_flags *flags)
{
	flags->flags[tab] = 1;
	flags->setting = 1;
	return (1);
}

static int  is_flags(int c, t_flags *flags)
{
	if (c == '#')
		return (set_flags(0, flags));
	if (c == '-')
		return (set_flags(1, flags));
	if (c == '+')
		return (set_flags(2, flags));
	if (c == ' ')
		return (set_flags(3, flags));
	if (c == '0')
		return (set_flags(4, flags));
	return (0);
}

int		set_ptf_flags(char *args, t_flags *flags)
{
	int i;

	i = 0;
	while (is_flags(args[i], flags))
		i++;
	return (i);
}

int set_ptf_precision(char *arg, va_list args, t_flags *flags)
{
    char    *tmp;
    int nb;

    tmp = arg;
    if (*arg == '.')
    {
        arg++;
        if (*arg == '*' && arg++)
        {
            nb = va_arg(args, int);
            flags->setting = (nb < 0) ? flags->setting : 1;
            nb = (nb < 0) ? flags->precision : nb;
            flags->precision = nb;
        }
        else
        {
            flags->precision = ft_atoi(&arg);
            flags->setting = 1;
        }
    }
    return (arg - tmp);
}
