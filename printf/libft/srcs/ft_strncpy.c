/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:53:26 by vpluchar          #+#    #+#             */
/*   Updated: 2016/11/22 01:53:34 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	v;

	v = 0;
	while (v < len && src[v])
	{
		dst[v] = src[v];
		v++;
	}
	while (v < len)
	{
		dst[v] = '\0';
		v++;
	}
	return (dst);
}
