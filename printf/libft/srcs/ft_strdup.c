/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:32:35 by vpluchar          #+#    #+#             */
/*   Updated: 2016/11/22 01:53:16 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		v;
	char	*dest;

	v = 0;
	while (src[v] != '\0')
		v++;
	dest = (char*)malloc(sizeof(*src) * (v + 1));
	if (!dest)
		return (dest);
	v = 0;
	while (src[v] != '\0')
	{
		dest[v] = src[v];
		v++;
	}
	dest[v] = '\0';
	return (dest);
}
