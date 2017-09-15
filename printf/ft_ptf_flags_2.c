/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_flags_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 12:36:52 by vpluchar          #+#    #+#             */
/*   Updated: 2017/08/23 12:36:52 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_ptf_long(va_list arg)
{
	t_flags		*flags;

	flags = get_ptf_flags(GET_FLAGS);
	flags->length = 'l';
	flags->setting = 1;
	flags->conversion = flags->conversion - 'A' + 'a';
	return (ft_ptf_conversion(arg, flags));
}

static void			write_address(t_flags *flags)
{
	char	*sign;

	sign = "0x";
	ft_ptf_join(flags, sign);
}

int					ft_ptf_address(va_list arg)
{
	void			*addr;
	t_flags	*flags;

	flags = get_ptf_flags(GET_FLAGS);
	addr = va_arg(arg, void *);
	ft_ptf_putnbr((unsigned long long)addr, 16, 'x');
	write_address(flags);
	return (0);
}

static int		write_float(t_flags *flags, double f)
{
	char	*sign;

	sign = NULL;
	if (f < 0)
		sign = "-";
	else if (flags->FLAGS_PLUS)
		sign = "+";
	else if (flags->FLAGS_SPACE)
		sign = " ";
	ft_ptf_join(flags, sign);
	return (0);
}

int				ft_ptf_float(va_list arg)
{
	double				f;
	t_flags		*flags;
	int					size;

	flags = get_ptf_flags(GET_FLAGS);
	f = va_arg(arg, double);
	size = (flags->precision < 0) ? 6 : flags->precision;
	ft_ptf_double(f, size, flags->conversion);
	write_float(flags, f);
	return (0);
}
