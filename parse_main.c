/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/02/22 17:27:24 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t      parse_format(const char *format, t_print *node)
{
    size_t     index_percent;
    size_t     flag_len;

    index_percent = find_percent(format);
    flag_len = check_flag(&format[++index_percent], node);

    node->width = check_width(&format[index_percent += flag_len]);
    index_percent += node->width < 0 ? 1: ft_countint(node->width);
    index_percent += node->width == -1 ? -1 : 0;

    node->precision = check_precision(&format[index_percent]);
    index_percent += node->precision < 0 ? 2 : ft_countint(node->precision) + 1;
    index_percent += node->precision == -1 ? -2 : 0;
    index_percent += node->precision == -3 ? -1 : 0;

    flag_len = check_size(&format[index_percent], node);

    index_percent += flag_len;
    node->type = check_type(format[index_percent]);

//    printf("flag: %s\n", node->flag);
//    printf("width: %d\n", node->width);
//    printf("prec: %d\n", node->precision);
//    printf("size: %s\n", node->size);
//    printf("type: %c\n", node->type);
    return (++index_percent);
}

char *parse_csp(va_list ap, t_print *node)
{
    char *tmp;

    if (node->width == -2)
        node->width = va_arg(ap, int);
    if (node->precision == -2)
        node->precision = va_arg(ap, int);

    if (node->type == 'c')
        tmp = parse_char((char)va_arg(ap, int), node);
    else if (node->type == 's')
        tmp = parse_str(va_arg(ap, char *), node);
    else
    tmp = parse_address(va_arg(ap, long), node);
    return (tmp);
}

char *parse_dioux_size(va_list ap, t_print *node)
{
    char *tmp;

    if (node->width == -2)
        node->width = va_arg(ap, int);
    if (node->precision == -2)
        node->precision = va_arg(ap, int);

    if (node->size[1] == 'l' && (node->type == 'd' || node->type == 'i'))
        tmp = manage_longlong(va_arg(ap, long long), node);
    else if (node->size[0] == 'l' && (node->type == 'd' || node->type == 'i'))
        tmp = manage_long(va_arg(ap, long), node);
    else if (node->size[1] == 'h' && (node->type == 'd' || node->type == 'i'))
        tmp = manage_signed_char((signed char)va_arg(ap, int), node);
    else if (node->size[0] == 'h' && (node->type == 'd' || node->type == 'i'))
        tmp = manage_short((short)va_arg(ap, int), node);
    else if (node->size[1] == 'l')
        tmp = manage_unsigned_longlong(va_arg(ap, unsigned long long), node);
    else if (node->size[0] == 'l')
        tmp = manage_unsigned_long(va_arg(ap, unsigned long), node);
    else if (node->size[1] == 'h')
        tmp = manage_unsigned_char((unsigned char)va_arg(ap, int), node);
    else
    tmp = manage_unsigned_short((unsigned short)va_arg(ap, int), node);
    return (tmp);
}

char *parse_dioux(va_list ap, t_print *node)
{
    char *tmp;

    if (node->width == -2)
        node->width = va_arg(ap, int);
    if (node->precision == -2)
        node->precision = va_arg(ap, int);

    if (node->type == 'X' || node->type == 'x' || node->type == 'o' || node->type == 'u')
        tmp = manage_unsigned_int(va_arg(ap, unsigned int), node);
    else if (node->type == 'd' || node->type == 'i')
        tmp = manage_int(va_arg(ap, int), node);
    else
        tmp = NULL;
    return (tmp);
}

char        *parse_feg(va_list ap, t_print *node)
{
    char *tmp;

    if (node->width == -2)
        node->width = va_arg(ap, int);
    if (node->precision == -2)
        node->precision = va_arg(ap, int);

    if (node->size[0] == 'L' && node->type == 'f')
        tmp = manage_float(va_arg(ap, long double), node);
    else if (node->type == 'f')
        tmp = manage_float(va_arg(ap, double), node);
    else
        tmp = NULL;
//    else if (node->size[0] == 'L' && node->type == 'e')
//        tmp = manage_exp(va_arg(ap, long double), node);
//    else if (node->type == 'e')
//        tmp = manage_exp(va_arg(ap, double), node);
//    else if (node->size[0] == 'L' && node->type == 'g')
//        tmp = manage_g(va_arg(ap, long double), node);
//    else if (node->type == 'g')
//        tmp = manage_g(va_arg(ap, double), node);
    return (tmp);
}


