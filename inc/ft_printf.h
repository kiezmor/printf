/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 05:05:53 by vpluchar          #+#    #+#             */
/*   Updated: 2017/10/26 07:38:13 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

# define GET			0
# define SET			1
# define SEND			2
# define NBR_SIZE		31
# define BUF_READ 		1
# define BUF_WRITE 		2
# define BUF_CHAR 		4
# define BUF_COLOR	 	8
# define BUF_SIZE		(4096 * 8)
# define RESET_FLAGS	0
# define GET_FLAGS 		1
# define FLAGS_HASH 	flags[0]
# define FLAGS_DASH 	flags[1]
# define FLAGS_PLUS 	flags[2]
# define FLAGS_SPACE	flags[3]
# define FLAGS_ZERO 	flags[4]

typedef struct		s_func
{
	int				(*ptrfunc)(va_list ap);
	char			key;
}					t_func;

typedef struct		s_flags
{
	int				flags[5];
	int				width;
	int				precision;
	char			length;
	char			conversion;
	int				setting;
}					t_flags;

int					ft_printf(char *format, ...);
int					ft_ptf_cands(char *fmt, va_list args);
int					ft_ptf_buff(char *str, int act);
int					ft_ptf_cands(char *fmt, va_list args);
int					ft_ptf_char(va_list ap);
int					ft_ptf_wchar(int wch);
int					ft_ptf_clr(char *str, va_list args);
int					ft_ptf_conversion(va_list ap, t_flags *flags);
void				ft_ptf_margin(char c, int a);
int					ft_ptf_string(va_list arg);
int					ft_ptf_number(va_list arg);
int					ft_ptf_percentage(va_list arg);
int					ft_ptf_float(va_list arg);
int					ft_ptf_address(va_list arg);
int					ft_ptf_long(va_list arg);
int					ft_ptf_fd(int fd, int act);
int					ft_ptf_int(va_list arg);
int					ft_ptf_join(t_flags *flags, char *str);
int					ft_ptf_tmp(char *str, int s, int act);
int					ft_ptf_uint(va_list arg);
t_flags				*ft_g_flags(int act);
int					ft_s_conv(char *arg, t_flags *flags);
int					ft_s_flags(char *args, t_flags *flags);
int					ft_s_prec(char *arg, va_list args, t_flags *flags);
int					ft_s_width(char *arg, va_list args, t_flags *flags);
int					ft_s_length(char *arg, t_flags *flags);
int					ft_ptf_putnbr(unsigned long long nbr, int base, int c);
double				ft_ptf_pow(int base, int pow);
int					ft_ptf_double(double f, int size, char conversion);
int					ft_ptf_double_sc(double f, int size);
int					ft_ptf_putdouble(double f, int size);
int					ft_ptf_atoi(char **arg);
int					ft_strequ(char *s1, char *s2);
int					ft_ptf_wstring(va_list ap, t_flags *flags);
int					ft_ptf_bin(va_list ap);

#endif
