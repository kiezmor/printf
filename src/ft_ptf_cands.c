/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_cands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 03:00:09 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/18 21:10:48 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_flags(char *fmt, va_list args, t_flags *flags)
{
	int	end;
	int	i;
	int	j;

	end = 1;
	i = 1;
	while (end)
	{
		j = 0;
		if (j += ft_s_flags(fmt + i, flags))
			i += j;
		else if (j += ft_s_width(fmt + i, args, flags))
			i += j;
		else if (j += ft_s_prec(fmt + i, args, flags))
			i += j;
		else if (j += ft_s_length(fmt + i, flags))
			i += j;
		else
			end = 0;
	}
	i += ft_s_conv(fmt + i, flags);
	return (i);
}

int			ft_ptf_cands(char *fmt, va_list args)
{
	int		i;
	t_flags	*flags;

	flags = ft_g_flags(RESET_FLAGS);
	i = set_flags(fmt, args, flags);
	ft_ptf_conversion(args, flags);
	ft_g_flags(RESET_FLAGS);
	return (i);
}
