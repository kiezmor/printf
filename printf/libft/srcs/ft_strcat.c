/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:00:05 by vpluchar          #+#    #+#             */
/*   Updated: 2016/11/23 03:29:12 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int v;
	int p;

	v = 0;
	p = -1;
	while (dest[v] != '\0')
		v++;
	while (src[++p] != '\0')
		dest[v + p] = src[p];
	dest[v + p] = '\0';
	return (dest);
}
