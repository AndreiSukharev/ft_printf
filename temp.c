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

char *check_another_percent(const char *format, size_t index, t_print *node)
{
    char *str;

    if (format[index] == '%' && !format[index + 1])
        return ("");
    index++;
    while (format[index] && format[index] != '%')
    {
        index++;
    }
    if (format[index] == '%')
    {
        str = parse_str("%", node);
        node->common_len += ft_strlen(str);
        return (str);
    }
    return (parse_str("", node));
}

int check_flag_0(t_print *node)
{
    if (node->flag[0] == '-' || node->flag[1] == '+' || node->flag[2] == ' ')
        return (0);
    return (1);

}

void find_and_del_x(char *str)
{
    int i;

    i = 0;
    while (str[i] && (str[i] != 'x' && str[i] != 'X'))
        i++;
    if (str[i] != 'x' || str[i] != 'X')
        str[i] = '0';
}

char    *parse_str_oux(char *ptr_arg, t_print *node)
{
    char    *str;
    size_t  len;
    size_t  width;

    len = ft_strlen(ptr_arg);
    node->width = node->width > 0 ? node->width : 0;
    width = len > (size_t)node->width ? len : (size_t)node->width;
    str = ft_strnew(width);
    if (node->flag[4] == '0' && node->precision == -1 && check_flag_0(node))
        ft_memset(str, '0', width);
    else
        ft_memset(str, ' ', width);
    oux_precision(str, node, node->len);
    find_and_del_x(ptr_arg);
    ft_strcpy_from(str, ptr_arg, node->flag[0] == '-' ? 0 : width-len);
    ft_strdel(&ptr_arg);
    return (str);
}