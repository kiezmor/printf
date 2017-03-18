/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 12:46:43 by lhordern          #+#    #+#             */
/*   Updated: 2017/03/18 23:49:11 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "./libft/includes/libft.h"

int		main()
{
        char	str[] = "Hello";
	char	c;
	int	i;

	c = '!';
	i = 100;
	ft_printf("%s world.\n%d %% same %c\n", str, i, c);
	printf("%s world.\n%d %% same %c\n", str, i, c);
	return (0);
}
