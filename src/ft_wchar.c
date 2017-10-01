/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 16:02:00 by vpluchar          #+#    #+#             */
/*   Updated: 2017/09/27 16:02:00 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static void		norme(int c, char *tab)
// {
// 	int	len;

// 	len = 0;
// 	tab[len++] = 0xFC | (c >> 30);
// 	tab[len++] = 0x80 | ((c >> 24) & 0x3F);
// 	tab[len++] = 0x80 | ((c >> 18) & 0x3F);
// 	tab[len++] = 0x80 | ((c >> 12) & 0x3F);
// 	tab[len++] = 0x80 | ((c >> 6) & 0x3F);
// 	tab[len++] = 0x80 | (c & 0x3F);
// 	tab[len] = 0;
// }

// static int		write_4byte_char(int c, char *tab)
// {
// 	int	len;

// 	len = 0;
// 	if (c < 0x200000)
// 	{
// 		tab[len++] = 0xF0 | (c >> 18);
// 		tab[len++] = 0x80 | ((c >> 12) & 0x3F);
// 		tab[len++] = 0x80 | ((c >> 6) & 0x3F);
// 		tab[len++] = 0x80 | (c & 0x3F);
// 	}
// 	else if (c < 0x4000000)
// 	{
// 		tab[len++] = 0xF8 | (c >> 24);
// 		tab[len++] = 0x80 | ((c >> 18) & 0x3F);
// 		tab[len++] = 0x80 | ((c >> 12) & 0x3F);
// 		tab[len++] = 0x80 | ((c >> 6) & 0x3F);
// 		tab[len++] = 0x80 | (c & 0x3F);
// 	}
// 	else
// 		norme(c, tab);
// 	tab[len] = 0;
// 	printf("%s|buff1|\n", tab);
// 	return (ft_ptf_buff(tab, BUF_WRITE));
// }

// static int		write_2byte_char(int c, char *tab)
// {
// 	int	len;

// 	len = 0;
// 	if (c < 0x80)
// 		tab[len++] = c;
// 	else if (c < 0x800)
// 	{
// 		tab[len++] = 0xC0 | (c >> 6);
// 		tab[len++] = 0x80 | (c & 0x3F);
// 	}
// 	else if (c < 0x10000)
// 	{
// 		tab[len++] = 0xE0 | (c >> 12);
// 		tab[len++] = 0x80 | ((c >> 6) & 0x3F);
// 		tab[len++] = 0x80 | (c & 0x3F);
// 	}
// 	tab[len] = 0;
// 	if (!tab[0])
// 	{
// 		printf("%s|buff2|\n", tab);
// 		return (ft_ptf_buff(tab, BUF_CHAR));
// 	}
// 	else
// 	{
// 		printf("%s|buff3|\n", tab);
// 		return (ft_ptf_buff(tab, BUF_WRITE));
// 	}
// }

int			ft_ptf_wchar(int c)
{
	// char	tab[10];

	// printf("%d|int c|\n", c);

	// if (c < 0x200000)
	// 	return (write_2byte_char(c, tab));
	// else
	// 	return (write_4byte_char(c, tab));
	char	t[4];
	if (ft_isprint(c))
		ft_wctomb(t, (wchar_t)c);
	if (t[0])
		return(ft_ptf_buff(t, BUF_WRITE));
	else
	return(ft_ptf_buff((char *)c, BUF_CHAR));
}
