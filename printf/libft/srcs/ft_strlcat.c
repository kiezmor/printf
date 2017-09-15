/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 23:18:42 by vpluchar          #+#    #+#             */
/*   Updated: 2016/11/28 05:11:54 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	v;
	size_t	p;

	v = 0;
	p = 0;
	while (dst[v] && v < size)
		v++;
	while (src[p] && (v + p + 1) < size)
	{
		dst[v + p] = src[p];
		p++;
	}
	if (v != size)
		dst[v + p] = '\0';
	return (v + ft_strlen(src));
}
