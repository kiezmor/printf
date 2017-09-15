/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 01:52:59 by vpluchar          #+#    #+#             */
/*   Updated: 2016/12/01 01:54:04 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int	*tab;
	int	v;

	if (min >= max)
		return (NULL);
	tab = (int*)malloc(sizeof(int) * (max - min));
	if (tab == NULL)
		return (NULL);
	v = 0;
	while (min < max)
	{
		tab[v] = min;
		min++;
		v++;
	}
	return (tab);
}
