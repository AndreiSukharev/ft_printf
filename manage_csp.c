/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/02/22 15:10:38 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_strcpy_from(char *dst, const char *src, size_t from)
{
    size_t i;
    size_t len;

    len = ft_strlen(dst);
    if (!dst || !src)
        return NULL;
    i = 0;
    while (src[i])
    {
        dst[from++] = src[i++];
    }
    dst[len] = '\0';
    return (dst);
}

char    *parse_str(char *arg, t_print *node)
{
    char    *str;
    char    *ptr_arg;

    if (!arg)
        arg = ft_strdup("(null)");
    node->len = ft_strlen(arg);
    if (node->precision >= 0 && node->type == 's' && node->len > node->precision )
    {
        ptr_arg = ft_strnew(node->precision);
        ptr_arg = ft_strncpy(ptr_arg, arg, node->precision);
    }
    else
        ptr_arg = arg;
    node->len = ft_strlen(ptr_arg);
    node->width = node->len > node->width ? node->len : node->width;
    str = ft_strnew(node->width);
    ft_strput_width(str, node);
    ft_strcpy_from(str, ptr_arg, node->flag[0] == '-' ? 0 : node->width-node->len);
//    ft_strdel(&arg);
    return (str);
}


char    *parse_char(char arg, t_print *node)
{
    char    *str;

    node->width = node->width > 1 ? node->width : 1;
    str = ft_strnew(node->width);
    node->common_len += arg == 0 ? 1 : 0;

    if (node->width <= 1)
    {
        str[0] = arg;
        return (str);
    }
    ft_strput_width(str, node);
    if (node->flag[0] == '-')
    {
        node->common_len += arg == 0 ? node->width - 1 : 0;
        str[0] = arg;
    }
    else
        str[node->width - 1] = arg;
    return (str);
}

char *parse_address(long address, t_print *node)
{
    int len;
    int count_long;
    char *str_base;
    char *str_prec;
    char *res;

    if (address == 0 && node->precision != 0)
        str_base = ft_strdup("0");
    else
        str_base = ft_base_hex(address);
    count_long = (int)ft_strlen(str_base);
    len = node->precision > count_long ? node->precision - count_long : 0;
    str_prec = ft_strnew((size_t)len + 2);
    oux_precision(str_prec, node, len + 2);
    res = ft_strjoin(str_prec, str_base);
    ft_strdel(&str_prec);
    ft_strdel(&str_base);


    return (parse_str(res, node));
}
