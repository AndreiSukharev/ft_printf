/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/02/22 17:27:30 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


size_t  check_another_percent(const char *format, t_print *node)
{
    char *str;
    size_t index_percent;
    size_t i;
    char *tmp;

    i = 0;
//    index_percent = find_percent(format);
//    while (format[i] != 'Z' && format[i] != 'd' && format[i] != 's' && format[i] != 'c' && format[i] != 'f' &&
//           format[i] != 'X' && format[i] != 'u' && format[i] != 'o' && i < index_percent)
//        i++;
//    if (format[index_percent] == '%')
//        str = parse_str(ft_strdup("%"), node);
//    else if (format[i] == 'd' || format[i] == 's' || format[i] == 'c' || format[i] == 'x' || format[i] == 'f' ||
//             format[i] == 'X' || format[i] == 'u' || format[i] == 'o')
//    {
//        node->type = format[i];
//        return (i + 1);
//    }
    if (format[0] == 0)
        return (0);
    str = parse_char(format[0], node);

    node->common_len += ft_strlen(str);
    node->res = ft_strjoin_all(str, node);
    ft_strdel(&str);
    return (1);
}

//size_t  check_another_percent(const char *format, t_print *node)
//{
//    char *str;
//    size_t index_percent;
//    size_t i;
//    char *tmp;
//
//    i = 0;
//    index_percent = find_percent(format);
//    while (format[i] != 'Z' && format[i] != 'd' && format[i] != 's' && format[i] != 'c' && format[i] != 'f' &&
//        format[i] != 'X' && format[i] != 'u' && format[i] != 'o' && i < index_percent)
//        i++;
//    if (format[i] == 'Z')
//    {
//        tmp = ft_strnew(index_percent - i);
//        ft_strlcat_all(tmp, format, index_percent - i);
//        str = parse_str(tmp, node);
//    }
//    else if (format[index_percent] == '%')
//        str = parse_str(ft_strdup("%"), node);
//    else if (format[i] == 'd' || format[i] == 's' || format[i] == 'c' || format[i] == 'x' || format[i] == 'f' ||
//        format[i] == 'X' || format[i] == 'u' || format[i] == 'o')
//    {
//        node->type = format[i];
//        return (i + 1);
//    }
//    else
//    {
//        node->width += index_percent < 2 ? 0 : index_percent - 1;
//        str = parse_str(ft_strdup(format), node);
//    }
//
//    node->common_len += ft_strlen(str);
//    node->res = ft_strjoin_all(str, node);
//    ft_strdel(&str);
//    return (index_percent);
//}

int check_width_after_va(int n, t_print * node)
{
    if (n < 0)
    {
        n *= -1;
        node->flag[0] = '-';
        return (n);
    }
    return (n);
}


int check_uox(t_print *node, char *arg)
{
    if (node->type == 'p')
        return (1);
    if (node->type == 'o' && node->flag[3] == '#')
    {
        if (arg[0] == '0' || (arg[0] != '0' && node->precision > 0))
            return (0);
        return (1);
    }
    if ((node->type == 'x' || node->type == 'X') && node->flag[3] == '#')
    {
        if (arg[0] == '0')
            return (0);
        return (1);
    }
    return (0);
}

int check_uox2(t_print *node, char *arg)
{
    if (node->type == 'p')
        return (1);
    if (node->type == 'o')
    {
        if ((arg[0] != '0' || node->flag[3] == '#' || node->precision > 0) || (node->precision == -1 && arg[0] == '0'))
            return (1);
    }
    if (node->type == 'x' || node->type == 'X' )
    {
        if (arg[0] != '0' || (arg[0] == '0' && node->precision != 0))
            return (1);
    }
    return (0);
}

void    count_width_oux(t_print *node,char *str_smthto)
{
    int  len;

    len = (int)ft_strlen(str_smthto);
    if (len > node->precision)
        node->len = len;
    else
        node->len = node->precision;
    if (check_uox(node, str_smthto))
        node->len += node->type == 'o' ? 1 : 2;
    if (check_uox2(node, str_smthto) == 0)
        node->len -= 1;
    node->width = node->len > node->width ? node->len : node->width;
}