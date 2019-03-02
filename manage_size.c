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

    sign = '0';
    if (arg < 0)
        sign = '-';
    else if (node->flag[1] == '+')
        sign = '+';
    else if (node->flag[2] == ' ')
        sign = ' ';
    arg *= arg < 0 ? -1 : 1;
    str_smthto = ft_longlong_toa(arg);
    count = ft_strlen(str_smthto);
    node->len = node->precision > count ? node->precision: count;
    node->len += (sign != '0') ? 1: 0;
    if (node->len == count)
    {
        if (str_smthto[0] == '0')
            str_smthto[0] = 0;
        return (parse_str(str_smthto, node));
    }
    return (manage_di(str_smthto, node, sign));
}

char    *manage_long(long arg, t_print *node)
{
    int count;
    char *str_smthto;
    char sign;

    sign = '0';
    if (arg < 0)
        sign = '-';
    else if (node->flag[1] == '+')
        sign = '+';
    else if (node->flag[2] == ' ')
        sign = ' ';
    arg *= arg < 0 ? -1 : 1;
    str_smthto = ft_long_toa(arg);
    count = ft_strlen(str_smthto);
    node->len = node->precision > count ? node->precision: count;
    node->len += (sign != '0') ? 1: 0;
    if (node->len == count)
    {
        if (str_smthto[0] == '0')
            str_smthto[0] = 0;
        return (parse_str(str_smthto, node));
    }
    return (manage_di(str_smthto, node, sign));
}

char    *manage_signed_char(signed char arg, t_print *node)
{
    int count;
    char *str_smthto;
    char sign;

    sign = '0';
    if (arg < 0)
        sign = '-';
    else if (node->flag[1] == '+')
        sign = '+';
    else if (node->flag[2] == ' ')
        sign = ' ';
    arg *= arg < 0 ? -1 : 1;
    str_smthto = ft_signed_char_toa(arg);
    count = ft_strlen(str_smthto);
    node->len = node->precision > count ? node->precision: count;
    node->len += (sign != '0') ? 1: 0;
    if (node->len == count)
    {
        if (str_smthto[0] == '0')
            str_smthto[0] = 0;
        return (parse_str(str_smthto, node));
    }
    return (manage_di(str_smthto, node, sign));
}

char    *manage_short(short arg, t_print *node)
{
    int count;
    char *str_smthto;
    char sign;

    sign = '0';
    if (arg < 0)
        sign = '-';
    else if (node->flag[1] == '+')
        sign = '+';
    else if (node->flag[2] == ' ')
        sign = ' ';
    arg *= arg < 0 ? -1 : 1;
    str_smthto = ft_short_toa(arg);
    count = ft_strlen(str_smthto);
    node->len = node->precision > count ? node->precision: count;
    node->len += (sign != '0') ? 1: 0;
    if (node->len == count)
    {
        if (str_smthto[0] == '0')
            str_smthto[0] = 0;
        return (parse_str(str_smthto, node));
    }
    return (manage_di(str_smthto, node, sign));
}

char    *manage_int(int arg, t_print *node)
{
    int count;
    char *str_smthto;
    char sign;

    sign = '0';
    if (arg < 0)
        sign = '-';
    else if (node->flag[1] == '+')
        sign = '+';
    else if (node->flag[2] == ' ')
        sign = ' ';
    arg *= arg < 0 ? -1 : 1;
    str_smthto = ft_itoa(arg);
    count = ft_strlen(str_smthto);
    node->len = node->precision > count ? node->precision: count;
    node->len += (sign != '0') ? 1: 0;
    if (node->len == count)
    {
        if (str_smthto[0] == '0')
            str_smthto[0] = 0;
        return (parse_str(str_smthto, node));
    }
    return (manage_di(str_smthto, node, sign));
}


