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
    index_percent = find_percent(format);
    while (format[i] != 'Z' && format[i] != 'd' && format[i] != 's' && format[i] != 'c' && format[i] != 'f' &&
        format[i] != 'X' && format[i] != 'u' && format[i] != 'o' && i < index_percent)
        i++;
    if (format[i] == 'Z')
    {
        tmp = ft_strnew(index_percent - i);
        ft_strlcat_all(tmp, format, index_percent - i);
        str = parse_str(tmp, node);
        ft_strdel(&tmp);
    }
    else if (format[index_percent] == '%')
        str = parse_str("%", node);
    else if (format[i] == 'd' || format[i] == 's' || format[i] == 'c' || format[i] == 'x' || format[i] == 'f' ||
        format[i] == 'X' || format[i] == 'u' || format[i] == 'o')
    {
        node->type = format[i];
        return (i + 1);
    }

    else
        str = parse_str(ft_strdup(format), node);

    node->common_len += ft_strlen(str);
    node->res = ft_strjoin(node->res, str);
    return (index_percent);
}

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