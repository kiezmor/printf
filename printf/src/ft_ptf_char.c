/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 03:35:39 by vpluchar          #+#    #+#             */
/*   Updated: 2017/09/08 03:35:39 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_ptf_wchar(int wch)
{
	write(1, &wch, sizeof(wint_t));
	return(1);
}

static int	write_char(va_list ap, t_flags *flags)
{
	int			size;
	char		tab[2];
	char		marg;
	int			wch;

	wch = va_arg(ap, int);
	tab[1] = 0;
	marg = (flags->FLAGS_ZERO) ? '0' : ' ';
	size = flags->width - 1;
	if (!flags->FLAGS_DASH)
		ft_ptf_margin(marg, size);
	if (flags->length == 'l')
		ft_ptf_wchar(wch);
	else
	{
		tab[0] = wch;
		ft_ptf_buff(tab, BUF_CHAR);
	}
	if (flags->FLAGS_DASH)
		ft_ptf_margin(' ', size);
	return (0);
}

int			ft_ptf_char(va_list ap)
{
	t_flags		*flags;
	char		tab[2];

	tab[1] = 0;
	flags = get_ptf_flags(GET_FLAGS);
	if (!flags->setting)
	{
		tab[0] = va_arg(ap, int);
		ft_ptf_buff(tab, BUF_CHAR);
	}
	else
		write_char(ap, flags);
	return (0);
}