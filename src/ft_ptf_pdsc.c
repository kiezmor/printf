/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_pdsc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 16:18:44 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/18 21:23:30 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int		ft_ptf_double_sc(double f, int size)
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

int		ft_ptf_atoi(char **arg)
{
	int		sum;
	int		sign;
	char	*str;

	str = *arg;
	sign = 1;
	sum = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		sum = (sum * 10) + *str - '0';
		str++;
	}
	*arg = str;
	return (sign * sum);
}

int		ft_ptf_fd(int fd, int act)
{
	static int	ret = 1;

	if (act == SET)
		ret = fd;
	return (ret);
}
