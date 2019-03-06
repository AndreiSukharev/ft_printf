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

int check_flag0(t_print *node)
{
    if (node->flag[4] == '0' && node->flag[0] != '-' && node->precision < 0)
        return (1);
    return (0);
}

void    set_width_and_sign_ForDI(char *str, t_print *node, char sign)
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

int      set_sign_For_pouxX(char *str, t_print *node)
{
    int index;

    index = 0;
    if (node->flag[3] != '#' && node->type != 'p')
        return (0);
    if (node->flag[0] == '-' || check_flag0(node))
    {
        if (node->type == 'p' || (node->flag[3] == '#' && (node->type == 'x' || node->type == 'X')))
        {
            str[index] = '0';
            str[++index] = (char)(node->type == 'X' ? 'X' : 'x');
        }
        else if (node->flag[3] == '#' && node->type == 'o')
            str[index] = '0';
    }
    else
    {
        index = node->width - node->len;
        if (node->type == 'p' || (node->flag[3] == '#' && (node->type == 'x' || node->type == 'X')))
        {
            str[index] = '0';
            str[++index] = (char)(node->type == 'X' ? 'X' : 'x');
        }
        else if (node->flag[3] == '#' && node->type == 'o')
            str[index] = '0';
    }
    return (++index);
}

int       poux_precision(char *str, t_print *node, int padding)
{
    int count_zero;

    count_zero = node->precision - node->len;
    if ((padding == 0 && node->flag[0] != '-') || check_flag0(node))
    {
        if (count_zero > 0)
            padding = node->width - node->len - count_zero;
        else
            padding = node->width - node->len;
    }
    while (count_zero-- > 0)
        str[padding++] = '0';
    return (padding);
}

