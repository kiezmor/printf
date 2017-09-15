/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_cands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 03:00:09 by vpluchar          #+#    #+#             */
/*   Updated: 2017/08/21 03:00:09 by vpluchar         ###   ########.fr       */
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
		if (j += set_ptf_flags(fmt + i, flags))
			i += j;
		else if (j += set_ptf_width(fmt + i, args, flags))
			i += j;
		else if (j += set_ptf_precision(fmt + i, args, flags))
			i += j;
		else if (j += set_ptf_length(fmt + i, flags))
			i += j;
		else
			end = 0;
	}
	i += set_ptf_conversion(fmt + i, flags);
	return (i);
}

int		ft_ptf_cands(char *fmt, va_list args)
{
	int	i;
	t_flags	*flags;
	
	flags = get_ptf_flags(RESET_FLAGS);
	i = set_flags(fmt, args, flags);
	ft_ptf_conversion(args, flags);
	get_ptf_flags(RESET_FLAGS);
	return (i);
}
