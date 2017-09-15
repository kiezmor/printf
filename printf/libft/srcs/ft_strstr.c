/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 02:04:33 by vpluchar          #+#    #+#             */
/*   Updated: 2016/11/27 21:53:26 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *b, const char *s)
{
	int j;

	j = 0;
	if (!(*s))
		return ((char *)b);
	while (*b)
	{
		while (b[j] == s[j] && s[j] && b[j])
			j++;
		if (!s[j])
			return ((char *)b);
		j = 0;
		b++;
	}
	return (NULL);
}
