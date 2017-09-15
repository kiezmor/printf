/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 02:12:48 by vpluchar          #+#    #+#             */
/*   Updated: 2016/11/25 05:51:54 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *l, size_t len)
{
	size_t	v;

	if (*l == '\0')
		return ((char *)b);
	v = ft_strlen(l);
	while (*b != '\0' && len-- >= v)
	{
		if (*b == *l && ft_memcmp(b, l, v) == 0)
			return ((char *)b);
		b++;
	}
	return (0);
}
