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
    size_t  len;
    size_t  width;

    if (node->precision >= 0)
    {
        ptr_arg = ft_strnew(ft_strlen(arg) - (size_t)node->precision);
        ptr_arg = ft_strncpy(ptr_arg, arg, (size_t)node->precision);
    }
    else
        ptr_arg = arg;
    len = ft_strlen(ptr_arg);
    node->width = node->width > 0 ? node->width : 0;
    width = len > (size_t)node->width ? len : (size_t)node->width;
    str = ft_strnew(width);
    ft_memset(str, ' ', width);
    str = ft_strcpy_from(str, ptr_arg, node->flag == '-' ? 0 : width-len);
    return (str);
}

char    *parse_char(char arg, t_print *node)
{
    char    *str;
    size_t  width;

    width = node->width > 1 ? (size_t)node->width : 1;
    str = ft_strnew(width);
    if (width <= 1)
    {
        str[0] = arg;
        return (str);
    }
    ft_memset(str, ' ', width);
    if (node->flag == '-')
        str[0] = arg;
    else
        str[width - 1] = arg;
    return (str);
}
