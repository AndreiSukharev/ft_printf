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

char    *manage_longlong(long long arg, t_print *node)
{
    int count;
    char *str_smthto;
    char sign;

    count = ft_count_longlong(arg);
    node->len = node->precision > count ? node->precision - count : 0;
    node->len += (arg < 0 || node->flag[1] == '+') ? 1: 0;
    str_smthto = ft_longlong_toa(arg);
    if (node->len == 0)
        return (parse_str(str_smthto, node));
    sign = '0';
    if (arg < 0)
        sign = '-';
    else if (node->flag[1] == '+')
        sign = '+';
    return (manage_di(str_smthto, node, sign));
}

char    *manage_long(long arg, t_print *node)
{
    int count;
    char *str_smthto;
    char sign;

    count = ft_count_long(arg);
    node->len = node->precision > count ? node->precision - count : 0;
    node->len += (arg < 0 || node->flag[1] == '+') ? 1: 0;
    str_smthto = ft_long_toa(arg);
    if (node->len == 0)
        return (parse_str(str_smthto, node));
    sign = '0';
    if (arg < 0)
        sign = '-';
    else if (node->flag[1] == '+')
        sign = '+';
    return (manage_di(str_smthto, node, sign));
}

char    *manage_signed_char(signed char arg, t_print *node)
{
    int count;
    char *str_smthto;
    char sign;

    count = ft_count_signed_char(arg);
    node->len = node->precision > count ? node->precision - count : 0;
    node->len += (arg < 0 || node->flag[1] == '+') ? 1: 0;
    str_smthto = ft_signed_char_toa(arg);
    if (node->len == 0)
        return (parse_str(str_smthto, node));
    sign = '0';
    if (arg < 0)
        sign = '-';
    else if (node->flag[1] == '+')
        sign = '+';
    return (manage_di(str_smthto, node, sign));
}

char    *manage_short(short arg, t_print *node)
{
    int count;
    char *str_smthto;
    char sign;

    count = ft_count_short(arg);
    node->len = node->precision > count ? node->precision - count : 0;
    node->len += (arg < 0 || node->flag[1] == '+') ? 1: 0;
    str_smthto = ft_short_toa(arg);
    if (node->len == 0)
        return (parse_str(str_smthto, node));
    sign = '0';
    if (arg < 0)
        sign = '-';
    else if (node->flag[1] == '+')
        sign = '+';
    return (manage_di(str_smthto, node, sign));
}

char    *manage_int(int arg, t_print *node)
{
    int count;
    char *str_smthto;
    char sign;

    count = ft_countint(arg);
    node->len = node->precision > count ? node->precision - count : 0;
    node->len += (arg < 0 || node->flag[1] == '+') ? 1: 0;
    str_smthto = ft_itoa(arg);
    if (node->len == 0)
        return (parse_str(str_smthto, node));
    sign = '0';
    if (arg < 0)
        sign = '-';
    else if (node->flag[1] == '+')
        sign = '+';
    return (manage_di(str_smthto, node, sign));
}


