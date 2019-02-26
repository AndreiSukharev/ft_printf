/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_addres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/02/22 17:26:53 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *manage_float(long double f, t_print *node)
{
    int i;
    long double dec;
    char *int_part;
    char *dec_part;
    char *res;

    i = (int)f;
    dec = f - (long double)i;
    int_part = ft_itoa(i);
    if (node->precision == -3 || node->precision == 0)
        return (parse_str(int_part, node));
    i = node->precision < 0 ? 6 : node->precision;
    int_part[ft_strlen(int_part)] = '.';
    dec *= ft_pow(10, i);
    dec_part = ft_strnew(ft_count_longlong((long long)dec));
    intToStr_float((long long)dec, dec_part, i);
    res = ft_strjoin(int_part, dec_part);
    ft_strdel(&dec_part);
    ft_strdel(&int_part);
    return (parse_str(res, node));
}


