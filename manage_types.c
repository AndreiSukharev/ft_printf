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

    if (arg[0] == '0' && node->type != 'o' && (node->precision == -3 || node->precision == 0))
        return (parse_str(ft_strnew(node->width < 0 ? 0 : node->width), node));
    else if (arg[0] == '0')
        return (arg);
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
    if (node->flag[4] == '0' && check_flag_0(node))
        return (parse_str_oux(res, node));
    return (parse_str(res, node));
}