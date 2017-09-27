/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_g_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <vpluchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 23:48:45 by vpluchar          #+#    #+#             */
/*   Updated: 2017/09/27 23:48:45 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void init(t_flags *flags)
{
    int i;
    i = 0;
    while (i < 5)
        flags->flags[i++] = 0;
    flags->width = 0;
    flags->precision = -1;
    flags->length = '0';
    flags->conversion = 0;
    flags->setting = 0;
}

t_flags *ft_g_flags(int act)
{
    static t_flags  flags;

    if (act == RESET_FLAGS)
        init(&flags);
    return (&flags);
}
