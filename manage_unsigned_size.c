/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_addres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/02/22 17:26:53 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *manage_unsigned_longlong(unsigned long long arg, t_print *node)
{
    char *str_smthto;

    if (node->type == 'u')
        str_smthto = ft_unsigned_longlong_toa(arg);
    else
        str_smthto = ft_base_xo_longlong(arg, node, node->type == 'o' ? 8 : 16);
    return (manage_uox(str_smthto, node));
}

char    *manage_unsigned_long(unsigned long arg, t_print *node)
{
    char *str_smthto;

    if (node->type == 'u')
        str_smthto = ft_unsigned_long_toa(arg);
    else
        str_smthto = ft_base_xo_long(arg, node, node->type == 'o' ? 8 : 16);
    return (manage_uox(str_smthto, node));
}

char    *manage_unsigned_char(unsigned char arg, t_print *node)
{
    char *str_smthto;

    if (node->type == 'u')
        str_smthto = ft_unsigned_char_toa(arg);
    else
        str_smthto = ft_base_xo(arg, node, node->type == 'o' ? 8 : 16);
    return (manage_uox(str_smthto, node));
}

char    *manage_unsigned_short(unsigned short arg, t_print *node)
{
    char *str_smthto;

    if (node->type == 'u')
        str_smthto = ft_unsigned_short_toa(arg);
    else
        str_smthto = ft_base_xo(arg, node, node->type == 'o' ? 8 : 16);
    return (manage_uox(str_smthto, node));
}

char    *manage_unsigned_int(unsigned int arg, t_print *node)
{
    char *str_smthto;

    if (node->type == 'u')
        str_smthto = ft_unsigned_int_toa(arg);
    else
        str_smthto = ft_base_xo(arg, node, node->type == 'o' ? 8 : 16);
    return (manage_uox(str_smthto, node));

}

