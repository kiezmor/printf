/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_pdsc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 16:18:44 by vpluchar          #+#    #+#             */
/*   Updated: 2017/09/15 16:18:44 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.c"

double	ft_ptf_pow(int base, int pow)
{
	double	ret;
	double	fbase;
	int		i;

	ret = 1.0;
	i = 0;
	fbase = (double)(ret / base);
	while (i != pow)
	{
		ret *= (pow >= 0) ? base : fbase;
		i += (pow >= 0) ? 1 : -1;
	}
	return (ret);
}

int	ft_ptf_double_sc(double f, int size)
{
	unsigned long long	nb;
	long double			r;
	int					i;

	f = (f < 0) ? -f : f;
	nb = f;
	if (nb)
		ft_ptf_putnbr(nb, 10, 0);
	else
		ft_ptf_tmp("0", -1, SET);
	if (size)
		ft_ptf_tmp("P", -1, SET);
	i = 0;
	r = f - nb;
	nb = (r * ft_ptf_pow(10, size));
	ft_ptf_putnbr(nb, 10, 0);
	return (0);
}
