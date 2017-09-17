/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_clr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 03:44:55 by vpluchar          #+#    #+#             */
/*   Updated: 2017/08/21 03:44:55 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_clr(char *clr, char *style)
{
	char    *base;
	char    balise[16];
	int i;
	int split;

	base = "\033[";
	split = (clr[0] && style[0]) ? 1 : 0;
	i = 0;
	while (!(*base == 0 && *clr == 0 && *style == 0))
	{
		if (*base)
			balise[i] = *base++;
		else if (*clr)
			balise[i] = *clr++;
		else if (split && !(split = 0))
			balise[i] = ';';
		else
			balise[i] = *style++;
		i++;
	}
	balise[i] = 'm';
	balise[i + 1] = 0;
	ft_ptf_buff(balise, BUF_WRITE);
	return (1);
}

static int	check_clr(char *tab, char *style)
{
	if (!*tab && *style)
	return (write_clr(style, tab));
	else if (ft_strequ(tab, "red"))
		return (write_clr("31", style));
	else if (ft_strequ(tab, "dark"))
		return (write_clr("30", style));
	else if (ft_strequ(tab, "white"))
		return (write_clr("37", style));
	else if (ft_strequ(tab, "green"))
		return (write_clr("32", style));
	else if (ft_strequ(tab, "yellow"))
		return (write_clr("33", style));
	else if (ft_strequ(tab, "blue"))
		return (write_clr("34", style));
	else if (ft_strequ(tab, "pink"))
		return (write_clr("35", style));
	else if (ft_strequ(tab, "cyan"))
		return (write_clr("36", style));
	else if (ft_strequ(tab, "eof"))
		return (write_clr("0", style));
	return (0);
}

static int	set_tab(char *str, char *tab, int val)
{
	int	i;
	int	write;

	i = 0;
	write = 0;
	if (val == 0 && (str[0] >= 'a' && str[0] <= 'z'))
		write = 1;
	if (val == 1 && (str[0] >= '0' && str[0] <= '9'))
		write = 1;
	if (val == 2 && (str[0] == '%'))
		write = 1;
	if (!write)
		return (0);
	while (!(str[i] == ':' || str[i] == '}'))
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = 0;
	if (str[i] == ':')
		i++;
	return (i);
}

static int	get_clr(char *str, int size, int j, va_list args)
{
	char	clr[size + 1];
	char	style[size + 1];
	char	arg[size + 1];
	int		i;
	int		ret;

	if (j == 1)
		return (0);
	i = 0;
	clr[0] = 0;
	style[0] = 0;
	arg[0] = 0;
	i += set_tab(str + i, clr, 0);
	i += set_tab(str + i, style, 1);
	i += set_tab(str + i, arg, 2);
	ret = check_clr(clr, style);
	if (arg[0] && (clr[0] || style[0]))
	{
		ft_ptf_cands(arg, args);
		ret = check_clr("e", "");
	}
	return (ret);
}

int	ft_ptf_clr(char *str, va_list args)
{
	int		i;
	int		j;

	str++;
	i = 0;
	while (!(str[i] == '}' || str[i] == 0))
		i++;
	j = (str[i] == 0) ? 1 : 2;
	i = (get_clr(str, i, j, args)) ? i + j : 0;
	if (!i)
	{
		i = 1;
		ft_ptf_buff("{", BUF_CHAR);
	}
	return (i);
}

int	ft_strequ(char *s1, char *s2)
{
	if (*s1 == 0)
		return (0);
	while (*s1)
	{
		if (*s1++ != *s2++)
			return (0);
	}
	return (1);
}
