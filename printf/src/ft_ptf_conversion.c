/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 17:46:31 by vpluchar          #+#    #+#             */
/*   Updated: 2017/08/21 17:46:31 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_func	g_flags[] =
{
	{ft_ptf_percentage, '%'},/**/
	{ft_ptf_int, 'd'},/**/
	{ft_ptf_int, 'i'},/**/
	{ft_ptf_uint, 'x'},/**/
	{ft_ptf_uint, 'X'},/**/
	{ft_ptf_uint, 'o'},/**/
	{ft_ptf_uint, 'u'},/**/
	{ft_ptf_long, 'D'},/**/
	{ft_ptf_long, 'U'},/**/
	{ft_ptf_long, 'O'},/**/
	{ft_ptf_long, 'C'},/**/
	{ft_ptf_long, 'S'},/**/
	{ft_ptf_long, 'F'},/**/
	{ft_ptf_long, 'E'},/**/
	{ft_ptf_number, 'n'},/**/
	{ft_ptf_string, 's'},
	{ft_ptf_char, 'c'},/*theor*/
	{ft_ptf_address, 'p'},/**/
	{ft_ptf_float, 'f'},/**/
	{ft_ptf_float, 'e'},/**/
	/*{ft_ptf_bin, 'b'},*/
	{NULL, -1}
};

static int	ptf_convertion(char c, va_list arg)
{
	int	i;

	i = 0;
	while (g_flags[i].key != -1)
	{
		if (g_flags[i].key == c)
			return (g_flags[i].ptrfunc(arg));
		i++;
	}
	return (1);
}

static int	invalid_conversion(t_flags *flags)
{
	char	tab[2];
	char	marg;

	if (!flags->conversion)
		return (0);
	tab[0] = flags->conversion;
	tab[1] = 0;
	marg = (flags->FLAGS_ZERO) ? '0' : ' ';
	if (!flags->FLAGS_DASH)
		ft_ptf_margin(marg, flags->width - 1);
	ft_ptf_buff(tab, BUF_CHAR);
	if (flags->FLAGS_DASH)
		ft_ptf_margin(' ', flags->width - 1);
	return (0);
}

int			ft_ptf_conversion(va_list ap, t_flags *flags)
{
	if (ptf_convertion(flags->conversion, ap))
		return (invalid_conversion(flags));
	return (0);
}
