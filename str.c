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


void ft_strput_width(char *str, t_print * node)
{
    if (node->flag[4] == '0' && node->precision == -1 && check_flag_0(node))
        ft_memset(str, '0', node->width);
    else
        ft_memset(str, ' ', node->width);
}

void ft_strlcat_all(char *restrict dst, const char *restrict src, size_t size)
{
    size_t		i;

    i = 0;
    while (i < size)
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}


char	*ft_strjoin_all(char *arg, t_print *node)
{
    char	*str;

    if (!node->res || !arg)
        return (0);
    str = ft_memalloc(node->common_len + 1);
    if (!str)
        return (NULL);
    ft_strlcat_all(str, node->res, node->common_len);
    ft_strcat(str, arg);
//    ft_strdel(&arg);
    ft_strdel(&node->res);
    return (str);
}