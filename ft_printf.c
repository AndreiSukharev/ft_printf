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

char *parse_what(va_list ap, t_print *node)
{
    char *arg;

    if (node->type == 's' || node->type == 'p' || node->type == 'c')
        arg = parse_csp(ap, node);
    else if (node->type == 'f' || node->type == 'e' || node->type == 'g')
        arg = parse_feg(ap, node);
    else if (node->size[0] == '0' && node->size[1] == '0' && (node->type == 'X' || node->type == 'x' ||
    node->type == 'o' || node->type == 'u' || node->type == 'd' || node->type == 'i'))
        arg = parse_dioux(ap, node);
    else
        arg = parse_dioux_size(ap, node);
    return (arg);
}

void main_result(const char *format, va_list ap, t_print *node)
{
    char    *arg;
    size_t  index;
    size_t  tmp;

    index = 0;
    while (format[index])
    {
        node->res = get_str_before_percent(&format[index], node);
//        node->common_len += ft_strlen(node->res);
        tmp = find_percent(&format[index]);
        if (format[index + tmp] == '\0')
            return;
        index += parse_format(&format[index], node);
        if (node->type == '0')
        {
            node->res = ft_strjoin(node->res, check_another_percent(format, tmp, node));
            return;
        }
        arg = parse_what(ap, node);
        node->common_len += ft_strlen(arg);
        node->res = ft_strjoin_all(arg, node);
//        ft_strdel(&arg);
        rewrite_tprint(node);
    }
}


int     ft_printf(const char * restrict format, ...)
{
    va_list ap;
    t_print *node;
    size_t len;

    va_start(ap, format);
    node = init_tprint();
    main_result(format, ap, node);
    va_end(ap);
    len = node->common_len;
    if (node->res)
    {
        if (len)
            write(1, node->res, len);
        del_tprint(&node);
        return ((int)len);
    }
    return (-1);
}
