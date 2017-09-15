/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:27:59 by vpluchar          #+#    #+#             */
/*   Updated: 2016/11/22 01:52:54 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp1;
	char	*tmp2;
	size_t	v;

	v = -1;
	tmp1 = (char *)src;
	tmp2 = (char *)dst;
	if (tmp1 < tmp2)
		while ((int)(--len) >= 0)
			*(tmp2 + len) = *(tmp1 + len);
	else
		while (++v < len)
			*(tmp2 + v) = *(tmp1 + v);
	return (dst);
}
