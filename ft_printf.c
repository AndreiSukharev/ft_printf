/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/02/16 16:18:11 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


size_t    parse_format(const char *format, t_print *node)
{
    size_t     index_percent;

    index_percent = find_percent(format);
    node->flag = check_flag(format[++index_percent]);

    node->width = check_width(&format[index_percent += node->flag == '1' ? 0 : 1]);
    index_percent += node->width < 0 ? 1: ft_countint(node->width);
    index_percent += node->width == -1 ? -1 : 0;

    node->precision = check_precision(&format[index_percent]);
    index_percent += node->precision < 0 ? 2 : ft_countint(node->precision) + 1;
    index_percent += node->precision == -1 ? -2 : 0;

    node->size = check_size(&format[index_percent]);

    index_percent += ft_strlen(node->size);
    node->type = check_type(format[index_percent]);

    printf("flag: %c\n", node->flag);
    printf("width: %d\n", node->width);
    printf("prec: %d\n", node->precision);
    printf("size: %s\n", node->size);
    printf("type: %c\n", node->type);
    return (++index_percent);
}

char *parse_args(va_list ap, t_print *node)
{
    char *tmp;

    if (node->width == -2)
        node->width = va_arg(ap, int);
    if (node->precision == -2)
        node->precision = va_arg(ap, int);

    if (node->type == 'c')
    {

        tmp = parse_char((char)va_arg(ap, int), node);
    }
    else if (node->type == 's')
    {
        tmp = parse_str(va_arg(ap, char *), node);
    }
    else if (node->type == 'p')
    {
        tmp = parse_address(va_arg(ap, long), node);
    }
    else
        tmp = NULL;
    return (tmp);
}

int     ft_printf(const char * restrict format, ...)
{
    va_list ap;
    char    *arg;
    size_t  index;
    char    *output;
    t_print *node;

    int     count = 0;

    index = 0;
    output = ft_strnew(0);
    va_start(ap, format);
    printf("%s\n", format);
//  while (count++ < 3) {
        output = get_str_before_percent(&format[index], output);
        node = init_tprint();
        index += parse_format(&format[index], node);
        arg = parse_args(ap, node);

        printf("|%s|", arg);

//        printf("flag: %c\n", node->flag);
//        printf("width: %d\n", node->width);
//        printf("prec: %d\n", node->precision);
//        printf("size: %s\n", node->size);
//        printf("type: %c\n\n", node->type);
        del_tprint(&node);
//    }
//    printf("|%s|\n", output);
////


//    while (count++ < 2)
//    {
//      get output before %
//      parse until %s: parse_format(node, format); return index;
//      get va_arg due to % node->type
//        arg = va_arg(ap, char *);
//      parse_arg(arg, node); return str;
//      output = ft_cat(output, str)
//        printf("%s\n", arg);
//    }
//    va_end(ap);
    return(-1);
}
