/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 07:48:29 by vpluchar          #+#    #+#             */
/*   Updated: 2016/11/28 08:08:58 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char *tmp;

	if (!(tmp = malloc(sizeof(char) * n + 1)))
		return (NULL);
	tmp = ft_strncpy(tmp, s, n);
	return (tmp);
}
