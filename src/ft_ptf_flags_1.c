/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_flags_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 22:43:24 by vpluchar          #+#    #+#             */
/*   Updated: 2017/08/21 22:43:24 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptf_percentage(va_list arg)
{
	t_flags	*flags;
	char			margin;

	(void)arg;
	flags = ft_g_flags(GET_FLAGS);
	margin = (flags->FLAGS_ZERO) ? '0' : ' ';
	if (!flags->FLAGS_DASH)
		ft_ptf_margin(margin, flags->width - 1);
	ft_ptf_buff("%", BUF_WRITE);
	if (flags->FLAGS_DASH)
		ft_ptf_margin(' ', flags->width - 1);
	return (0);
}

int		ft_ptf_number(va_list arg)
{
	t_flags	*flags;
	int				*ptr;

	flags = ft_g_flags(GET_FLAGS);
	ptr = va_arg(arg, int *);
	*ptr = ft_ptf_buff(NULL, 0);
	return (0);
}

static void	string_rules(t_flags *flags, char *str)
{
	if (str)
	{
		if (!*str)
			flags->precision = 0;
	}
}

int			ft_ptf_string(va_list arg)
{
	char				*str;
	t_flags		*flags;
	int					size;

	flags = ft_g_flags(GET_FLAGS);
	if (flags->length == 'l')
		return (ft_ptf_wstring(arg, flags));
	str = va_arg(arg, char *);
	string_rules(flags, str);
	size = ft_ptf_tmp(str, flags->precision, SET);
	flags->precision = (flags->precision > size) ? size : flags->precision;
	ft_ptf_join(flags, NULL);
	return (0);
}

void	ft_ptf_margin(char c, int a)
{
	int		i;

	if (a > 0)
	{
		i = 0;
		while (i++ < a)
			ft_ptf_buff(&c, BUF_CHAR);
	}
}

int	ft_ptf_fd(int fd, int act)
{
	static int	ret = 1;

	if (act == SET)
		ret = fd;
	return (ret);
}
