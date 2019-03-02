/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/02/16 16:18:11 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t   check_flag(const char *format, t_print *node)
{
    size_t i;

    i = 0;
    while (format[i] == '-' || format[i] == '+' || format[i] == ' ' || format[i] == '#' || format[i] == '0')
    {
        if (format[i] == '-')
        {
            node->flag[0] = '-';
        }
        else if (format[i] == '+')
        {
            node->flag[1] = '+';
        }
        else if (format[i] == ' ')
        {
            node->flag[2] =  node->flag[1] != '+' ? ' ' : '1';
        }
        else if (format[i] == '#')
        {
            node->flag[3] = '#';
        }
        else if (format[i] == '0')
        {
            node->flag[4] = '0';
        }
        i++;
    }
    return (i);
}

size_t    check_width(const char *format, t_print *node)
{
    size_t  i;
    char    *str;

    i = 0;
    if (format[0] == '*')
    {
        node->width = -2;
        i++;
    }
    while (format[i] >= '0' && format[i] <= '9')
        i++;
    if (i == 0)
        return (0);
    if (i == 1 && node->width == -2)
        return (1);
    if (format[i] == '*')
    {
        node->width = -2;
        return (i + 1);
    }
    if (node->width == -2)
        node->next_arg = 1;
    str = ft_strnew(i);
    str = ft_strncat(str, format, i);
    node->width = ft_atoi(str);
    ft_strdel(&str);
    return (i);
}

size_t   check_precision(const char *format, t_print *node)
{
    size_t  i;
    char    *str;

    i = 1;
    if (format[0] != '.')
        return (0);
    if (format[1] == '*')
    {
        node->precision = -2;
        return (2);
    }
    while (format[i] >= '0' && format[i] <= '9')
        i++;
    if (i == 1)
    {
        node->precision = -3;
        return (1);
    }
    i--;
    str = ft_strnew(i);
    str = ft_strncat(str, &format[1], i);
    node->precision = ft_atoi(str);
    ft_strdel(&str);
    return (i + 1);
}

size_t     check_size(const char *format, t_print *node)
{
    size_t  i;

    i = 0;
    if (format[0] == 'h')
    {
        node->size[0] = 'h';
        i = 1;
        if (format[1] == 'h')
        {
            node->size[1] = 'h';
            return (2);
        }
    }
    if (format[0] == 'l')
    {
        node->size[0] = 'l';
        i = 1;
        if (format[1] == 'l')
        {
            node->size[1] = 'l';
            return (2);
        }
    }
    else if (format[0] == 'L')
    {
        node->size[0] = 'L';
        return (1);
    }
    return (i);
}

size_t    check_type(char format, t_print *node)
{
    if (format == 'c' || format == 's' || format == 'p' || format == 'd' || format == 'i' || format == 'o' ||
        format == 'u' || format == 'x' || format == 'X' || format == 'f'|| format == 'e' || format == 'g'
        || format == 'b'|| format == 'r' || format == 'k')
    {
        node->type = format;
        return(1);
    }
    else
        return (0);
}