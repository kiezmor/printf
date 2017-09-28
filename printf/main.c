/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 05:05:43 by vpluchar          #+#    #+#             */
/*   Updated: 2017/05/24 18:51:25 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "inc/ft_printf.h"

int	main(void)
{
	char	*str;
	char	ch;
	int		i;

	str = "Hello";
	ch = '!';
	i = 100;
	// int		p = 0;
	// while (p++ <= 100000 * 100)
	
	printf("%s\n", "------------------------------------------------");

	ft_printf("[%s world.\n%d %% same %c\n %s]\n", str, i, ch, "try");
	ft_printf("{red}%b{eof}\n", 125);
	// ft_printf("[FUCKING CHAR WITHOUT CAST /%lc\\]\n", ch);
	// ft_printf("i:%i\n", 300);
	// ft_printf("%hhd\n", 30000);
	
	// printf("%s\n", "------------------------------------------------");

	// long int z = 3000000;

	// printf("|%s world.\n% d %% same %c\n %s|\n", str, i, ch, "try");
	// printf("|FUCKING CHAR WITH CAST /%lc\\|\n", ch);
	// printf("i:%i\n", 300);
	// printf("D:%ld\n", z);

	printf("%s\n", "------------------------------------------------");
	
	wchar_t	wc = L'é';
	wchar_t	*blbl = L"|Hello, world!|";
	printf("|WC:%C|\n", wc);
	printf("|WS:%S|\n", blbl);

	ft_printf("[%S]\n", blbl);
	ft_printf("[%C]\n", wc);

	// printf("%s\n", "------------------------------------------------");
	// int		a,b;
	// float	c,d;

	// a = 15;
	// b = a / 2;
	// printf("|%d|\n",b);
	// printf("|%4d|\n",b);
	// printf("|%04d|\n",b);
	// c = 15.3;
	// d = c / 3;
	// printf("|%3.2f|\n",d);

	printf("%s\n", "------------------------------------------------");

	// printf("Float number: |%8.2f|\n", 1234.14159);
	// printf("Hexadecimal: %x\n", 255);
	// printf("Octal: %o\n", 10);
	// printf("Unsigned value: %u\n", 150);
	int	n = 233;
	char	tab;
	// ft_itoa(n,tab, 10);
	// printf("%s\n", tab);
	tab = n;
	ft_printf("%C\n", tab);

	printf("%s\n", "------------------------------------------------");

	printf(":%s:\n", "Hello, world!");
	printf(":%15s:\n", "Hello, world!");
	printf(":%.10s:\n", "Hello, world!");
	printf(":%-10s:\n", "Hello, world!");
	printf(":%.*s:\n", 10, "Hello, world!");
	printf(":%-15s:\n", "Hello, world!");
	printf(":%.15s:\n", "Hello, world!");
	printf(":%15.10s:\n", "Hello, world!");
	printf(":%-15.10s:\n", "Hello, world!");

	ft_printf("|%s|\n", "Hello, world!");
	ft_printf("|%15s|\n", "Hello, world!");
	ft_printf("|%.10s|\n", "Hello, world!");
	ft_printf("|%-10s|\n", "Hello, world!");
	ft_printf("|%.*s|\n", 10, "Hello, world!");
	ft_printf("|%-15s|\n", "Hello, world!");
	ft_printf("|%.15s|\n", "Hello, world!");
	ft_printf("|%15.10s|\n", "Hello, world!");
	ft_printf("|%-15.10s|\n", "Hello, world!");

	printf("%s\n", "------------------------------------------------");
	return (0);
}
