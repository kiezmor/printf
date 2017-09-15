/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:33:43 by vpluchar          #+#    #+#             */
/*   Updated: 2016/11/22 01:52:37 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*p;
	size_t	v;

	v = -1;
	p = dest;
	while (++v < n)
	{
		*(p + v) = *((unsigned char *)src + v);
		if (*((unsigned char *)src + v) == (unsigned char)c)
			return (dest + v + 1);
	}
	return (NULL);
}
