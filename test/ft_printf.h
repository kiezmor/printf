/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhordern <lhordern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 10:33:35 by lhordern          #+#    #+#             */
/*   Updated: 2013/12/18 19:50:00 by lhordern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

# define NB_FLAG 4

typedef struct   s_flag
{
	char		key;
	int			(*ptrfunc)(va_list ap);
}				t_flag;

int		ft_printf(const char *format, ...);
int		ft_checkflag(char flag, va_list args);
int		flag_s(va_list ap);
int		flag_c(va_list ap);
int		flag_d(va_list ap);
int		flag_p(va_list ap);

#endif /* ! FT_PRINTF_H */
