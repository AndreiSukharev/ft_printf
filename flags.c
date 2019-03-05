/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/02/22 17:26:53 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    set_width_and_sign(char *str, t_print *node, char sign)
{
    ft_strput_width(str, node);
    if (sign == '0')
        return;
    if (node->flag[0] == '-' || (node->flag[4] == '0' && node->precision == -1))
        str[0] = sign;
    else
        str[node->width - node->len] = sign;
}
size_t       di_precision(char *str, t_print *node, int count_zero)
{
    size_t     i;

    if (!count_zero || node->precision == -1)
    {
        if (str[0] == '-' || str[0] == '+')
            return (1);
        return (0);
    }
    if (node->flag[0] == '-' )
    {
        if (str[0] != '-' && str[0] != '+')
            i = 0;
        else
            i = 1;
    }
    else
        i = node->width - node->precision;
    while (count_zero-- > 0)
        str[i++] = '0';
    return (i);
}

void       oux_precision(char *str, t_print *node, int len)
{
    char    c;
    int     i;

    i = 0;
    c = ' ';
    if (node->flag[4] == '0' || node->precision != -1)
        c = '0';
    if (node->type == 'p' || (node->flag[3] == '#' && (node->type == 'x' || node->type == 'X')))
    {
        str[0] = '0';
        str[1] = (char)(node->type == 'X' ? 'X' : 'x');
        i = 2;
    }
    else if (node->flag[3] == '#' && node->type == 'o')
    {
        str[0] = '0';
        i = 1;
        len--;
    }
    while (i < len)
        str[i++] = c;
}

