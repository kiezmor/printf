/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 23:24:36 by vpluchar          #+#    #+#             */
/*   Updated: 2016/11/28 05:06:21 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	int		a;
	int		b;
	int		c;
	char	*str;

	a = 0;
	c = 0;
	if (!(s))
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (s[a] != '\0')
		a++;
	b = a;
	a--;
	while ((s[a] == ' ' || s[a] == '\n' || s[a] == '\t') && a >= 0)
	{
		c++;
		a--;
	}
	str = (char *)malloc(sizeof(char) * (b - c) + 1);
	if (str == NULL)
		return (NULL);
	str[b - c] = '\0';
	return (ft_strncpy(str, s, b - c));
}
