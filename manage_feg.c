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

char   *add_float(char *str_smthto, t_print *node)
{
    char *str_width;
    char *dup;
    char sign;

    node->precision = -1;
    sign = '0';
    if (str_smthto[0] == '-')
        sign = '-';
    else if (node->flag[1] == '+')
        sign = '+';
    else if (node->flag[2] == ' ')
        sign = ' ';
    node->len = ft_strlen(str_smthto) + (sign != '0' && str_smthto[0] != '-' ? 1 : 0);
    node->width = node->len > node->width ? node->len : node->width;
    str_width = ft_strnew(node->width);
    set_width_and_sign_ForDI(str_width, node, sign);
    sign = sign == '0' ? 0 : 1;
    if (str_smthto[0] == '-')
    {
        dup = ft_strdup(&str_smthto[1]);
        ft_strcpy_from(str_width, dup, node->flag[0] == '-' ? 1 : node->width - node->len + 1);
        ft_strdel(&dup);
    }
    else
        ft_strcpy_from(str_width, str_smthto, node->flag[0] == '-' ? sign : node->width - node->len + sign);
    ft_strdel(&str_smthto);
    return (str_width);
}

char    *manage_double_f(long double f, t_print *node)
{
    long i;
    long double dec;
    char *int_part;
    char *dec_part;
    char *res;

    i = (long)f;
    dec = f - i;
    int_part = ft_long_toa(i);
    if (node->precision == 0)
        return (add_float(int_part, node));
    node->precision = node->precision == -1 ? 6 : node->precision;
    dec *= dec < 0 ? -1 : 1;
    dec *= ft_pow(10, node->precision + 1);
    dec += (long long)dec % 10 == 9 ? 1 : 0;
    dec /= 10;
    dec_part = ft_strnew(ft_count_longlong((long long)dec) + 1);
    intToStr_float((long long)dec, dec_part, node->precision);
    res = ft_strjoin(int_part, dec_part);
    ft_strdel(&dec_part);
    ft_strdel(&int_part);
    return (add_float(res, node));
}

//char *manage_double_exp(long double f, t_print *node)
//{
//
//}

char    *manage_longfloat(long double f, t_print *node)
{
    int i;
    long double dec;
    char *int_part;
    char *dec_part;
    char *res;

    i = (int)f;
    dec = f - (long double)i;
    int_part = ft_itoa(i);
    if (node->precision == 0)
        return (parse_str(int_part, node));
    i = node->precision == -1 ? 6 : node->precision;
    int_part[ft_strlen(int_part)] = '.';
    dec *= ft_pow(10, i);
    dec_part = ft_strnew(ft_count_longlong((long long)dec));
    intToStr_float((long long)dec, dec_part, i);
    res = ft_strjoin(int_part, dec_part);
    ft_strdel(&dec_part);
    ft_strdel(&int_part);
    return (parse_str(res, node));
}


