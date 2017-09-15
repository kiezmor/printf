/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 12:33:37 by vpluchar          #+#    #+#             */
/*   Updated: 2017/08/23 12:33:37 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sign_len(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int	marg_conversion(int c)
{
	if (c == 's')
		return (' ');
	else
		return ('0');
}

int			ft_ptf_join(t_flags *flags, char *str)
{
	int		size;
	int		prec;
	char	marg;

	size = ft_ptf_tmp(NULL, 0, GET);
	prec = (size > flags->precision) ? size : flags->precision;
	marg = (flags->FLAGS_ZERO) ? '0' : ' ';
	flags->width -= sign_len(str);
	if (!flags->FLAGS_DASH)
	{
		if (marg == '0')
			ft_ptf_buffer(str, BUF_WRITE);
		ft_ptf_margin(marg, flags->width - prec);
	}
	if (marg == ' ')
		ft_ptf_buffer(str, BUF_WRITE);
	if (prec > size && size)
		ft_ptf_margin(marg_conversion(flags->conversion), prec - size);
	ft_ptf_tmp(NULL, 0, SEND);
	if (flags->FLAGS_DASH)
		ft_ptf_margin(' ', flags->width - prec);
	return (0);
}
