/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 15:50:03 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/18 22:04:53 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		octet_size(int c)
{
	if (c < 0x80)
		return (1);
	else if (c < 0x800)
		return (2);
	else if (c < 0x10000)
		return (3);
	else if (c < 0x200000)
		return (4);
	else if (c < 0x4000000)
		return (5);
	else
		return (6);
}

static int		w_prec(int *str, int prec, int *tron)
{
	int	i;
	int	j;
	int	d;
	int	tmp;

	i = 0;
	j = 0;
	tmp = 0;
	if (!str)
		return (prec);
	while (str[i])
	{
		tmp = octet_size(str[i]);
		if ((d = j + tmp) >= prec)
		{
			if (d == prec)
				i++;
			else
				*tron -= tmp - (d - prec);
			return (i);
		}
		j += tmp;
		i++;
	}
	return (i);
}

static int		wstring_len(int *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		return (6);
	while (str[i])
		j += octet_size(str[i++]);
	return (j);
}

static void		write_wstring(int *str, int p, int len)
{
	if (p >= 0)
	{
		while (len--)
			ft_ptf_wchar(*str++);
	}
	else
	{
		while (*str)
			ft_ptf_wchar(*str++);
	}
}

int				ft_ptf_wstring(va_list ap, t_flags *flags)
{
	int		*str;
	int		prec;
	int		l_prec;
	int		len;
	char	marg;

	str = va_arg(ap, int*);
	len = wstring_len(str);
	prec = (flags->precision >= 0) ? flags->precision : -1;
	l_prec = (prec > 0) ? w_prec(str, prec, &prec) : 0;
	len = (prec >= 0 && prec < len) ? prec : len;
	marg = (flags->FLAGS_ZERO) ? '0' : ' ';
	if (!flags->FLAGS_DASH)
		ft_ptf_margin(marg, flags->width - len);
	if (!str)
		ft_ptf_buff("(null)", BUF_WRITE);
	else
		write_wstring(str, prec, l_prec);
	if (flags->FLAGS_DASH)
		ft_ptf_margin(' ', flags->width - len);
	return (0);
}
