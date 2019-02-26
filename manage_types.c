/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/02/22 17:26:53 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//char   *manage_di(int n, t_print *node)
//{
//    int len;
//    int count_int;
//    char *str_itoa;
//    char *str_prec;
//    char *res;
//
//    count_int = ft_countint(n);
//    len = node->precision > count_int ? node->precision - count_int : 0;
//    len += (n < 0 || node->flag[1] == '+') ? 1: 0;
//    str_itoa = ft_itoa(n);
//    if (len == 0)
//        return (parse_str(str_itoa, node));
//    str_prec = ft_strnew(len);
//    if (n < 0)
//        str_prec[0] = '-';
//    else if (node->flag[1] == '+')
//        str_prec[0] = '+';
//    di_precision(str_prec, node, len);
//    res = ft_strjoin(str_prec, n < 0 ? &str_itoa[1] : str_itoa);
//    ft_strdel(&str_prec);
//    ft_strdel(&str_itoa);
//    return (parse_str(res, node));
//}

char   *manage_di(char *str_smthto, t_print *node, char sign)
{
    char *str_prec;
    char *res;

    str_prec = ft_strnew(node->len);
    if (sign != '0')
        str_prec[0] = sign;
    di_precision(str_prec, node);
    res = ft_strjoin(str_prec, sign == '-' ? &str_smthto[1] : str_smthto);
    ft_strdel(&str_prec);
    ft_strdel(&str_smthto);
    return (parse_str(res, node));
}

char *manage_uox(char *arg, t_print *node)
{
    char *str_prec;
    char *res;
    int count;

    count = (int)ft_strlen(arg);
    node->len = node->precision > count ? node->precision - count : 0;
    if (node->flag[3] == '#' && (node->type == 'x' || node->type == 'X'))
        node->len += 2;
    else if (node->flag[3] == '#' && node->type == 'o')
        node->len += 1;
    if (node->len == 0)
        return (parse_str(arg, node));
    str_prec = ft_strnew(node->len);
    oux_precision(str_prec, node, node->len);
    res = ft_strjoin(str_prec, arg);
    ft_strdel(&str_prec);
    ft_strdel(&arg);
    return (parse_str(res, node));
}

//char *manage_uox(unsigned int arg, t_print *node)
//{
//    int len;
//    int count_long;
//    char *str_base;
//    char *str_prec;
//    char *res;
//
//    if (node->type == 'u')
//        str_base = ft_unsigned_int_toa(arg);
//    else
//        str_base = ft_base_xo(arg, node, node->type == 'o' ? 8 : 16);
//    count_long = (int)ft_strlen(str_base);
//    len = node->precision > count_long ? node->precision - count_long : 0;
//    if (node->flag[3] == '#' && (node->type == 'x' || node->type == 'X'))
//        len += 2;
//    else if (node->flag[3] == '#' && node->type == 'o')
//        len += 1;
//    if (len == 0)
//        return (parse_str(str_base, node));
//    str_prec = ft_strnew(len);
//    oux_precision(str_prec, node, len);
//    res = ft_strjoin(str_prec, str_base);
//    ft_strdel(&str_prec);
//    ft_strdel(&str_base);
//    return (parse_str(res, node));
//}
