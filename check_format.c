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

char    check_flag(char format)
{
    if (format == '-')
        return ('-');
    else if (format == '+')
        return ('+');
    else if (format == ' ')
        return (' ');
    else if (format == '#')
        return ('#');
    else if (format == '0')
        return ('0');
    else
        return ('1');

}

int    check_width(const char *format)
{
    size_t  i;
    char    *str;
    int     res;

    i = 0;
    if (format[0] == '*')
    {
        return (-2);
    }
    while (format[i] >= '0' && format[i] <= '9')
    {
        i++;
    }
    if (i == 0)
        return (-1);
    str = ft_strnew(i);
    str = ft_strncat(str, format, i);
    res = ft_atoi(str);
    ft_strdel(&str);
    return (res);
}

int    check_precision(const char *format)
{
    size_t  i;
    char    *str;
    int     res;

    i = 1;
    if (format[0] != '.')
        return (-1);
    if (format[1] == '*')
        return (-2);
    while (format[i] >= '0' && format[i] <= '9')
        i++;
    if (i == 1)
        return (0);
    i--;
    str = ft_strnew(i);
    str = ft_strncat(str, &format[1], i);
    res = ft_atoi(str);
    ft_strdel(&str);
    return res;
}

char    *check_size(const char *format)
{
    size_t  i;
    char    *res;

    i = 0;
    if (format[0] == 'h')
    {
        if (format[1] == 'h')
            i = 2;
        else
            i = 1;
    }
    else if (format[0] == 'l')
    {
        if (format[1] == 'l')
            i = 2;
        else
            i = 1;
    }
    else if (format[0] == 'L')
        i = 1;
    res = ft_strnew(i);
    res = ft_strncat(res, &format[0], i);
    return (res);
}

char    check_type(char format)
{
    if (format == 'c' || format == 's' || format == 'p' || format == 'd' || format == 'i' || format == 'o' ||
        format == 'u' || format == 'x' || format == 'X' || format == 'f')
        return(format);
    else
        return ('0');
}