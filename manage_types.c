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
    char *str_width;
    size_t len_str;
    size_t padding_prec;

    len_str = ft_strlen(str_smthto);
    node->width = node->len > node->width ? node->len : node->width;
    str_width = ft_strnew(node->width);
    set_width_and_sign(str_width, node, sign);
    padding_prec = di_precision(str_width, node, node->precision - len_str);
    ft_strcpy_from(str_width, str_smthto, node->flag[0] == '-' ? padding_prec : node->width-len_str);
    ft_strdel(&str_smthto);
    return (str_width);
}

char *manage_uox(char *arg, t_print *node)
{
    char *str_prec;
    char *res;
    int count;

    if (arg[0] == '0' && (node->precision == -3 || node->precision == 0) && (node->type != 'o' || node->flag[3] != '#'))
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
