/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 01:52:35 by vpluchar          #+#    #+#             */
/*   Updated: 2016/11/22 01:53:05 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	v;

	v = -1;
	while (++v < (int)ft_strlen(s) + 1)
		if (*(s + v) == (char)c)
			return ((char *)s + v);
	return (NULL);
}
