/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 05:05:24 by vpluchar          #+#    #+#             */
/*   Updated: 2017/05/24 19:04:24 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(char *fmt, ...)
{
	va_list		args;
	t_flags		*flags;

	flags = ft_g_flags(GET_FLAGS);
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			fmt += ft_ptf_cands(fmt, args);
		else if (*fmt == '{')
			fmt += ft_ptf_clr(fmt, args);
		else
			ft_ptf_buff(fmt++, BUF_CHAR);
	}
	va_end(args);
	if (flags->longs != 0)
		return (flags->longs);
	else
		return (ft_ptf_buff(fmt, BUF_READ));
}
