/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:12:53 by vpluchar          #+#    #+#             */
/*   Updated: 2016/11/23 00:24:54 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, int nb)
{
	int v;
	int p;

	v = 0;
	p = -1;
	while (dest[v] != '\0')
		v++;
	while (src[++p] != '\0' && p < nb)
		dest[v + p] = src[p];
	dest[v + p] = '\0';
	return (dest);
}
