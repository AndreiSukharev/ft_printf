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

void       di_precision(char *str, t_print *node)
{
    char    c;
    int     i;

    i = 0;
    c = ' ';
    if (node->flag[4] == '0' || node->precision != -1)
        c = '0';
    if (str[0] == '-' || str[i] =='+')
        i++;
    while (i < node->len)
        str[i++] = c;

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
    }
    while (i < len)
        str[i++] = c;

}

