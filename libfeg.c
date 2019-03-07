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


int check_flag_g(t_print *node, long i)
{
    node->precision = node->precision == -1 ? 6 : node->precision;
    node->precision = node->precision == 0 ? 1 : node->precision;
    if (node->len <= node->precision)
    {
        node->precision -= i != 0 ? node->len : 0;
        return (1);
    }
    else
    {
        if (node->precision == 6)
            node->precision = 5;
        else
            node->precision = node->precision != 0 ? node->precision - 1 : 0;
        node->type = 'e';
    }
    return (0);
}

long long ft_pow(long long a, int b)
{
    int tmp;

    tmp = (int)a;
    while (--b)
        a *= tmp;
    return (a);
}

void reverse(char *str, int len)
{
    int i;
    int j;
    int temp;

    i = 0;
    j = len-1;
    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

long long str_to_float(long long x, char str[], t_print *node)
{
    int i;

    i = 0;
    while (x)
    {
        str[i++] = (char)((x % 10) + '0');
        x = x/10;
    }
    if (node->flag[3] == '#' || node->precision > 0)
        str[i++] = '.';
    while (i < node->precision)
        str[i++] = '0';
    reverse(str, i);
    str[i] = '\0';
    return i;
}

void    add_exp(char *str, int leni, int sign)
{
    str[0] = 'e';
    str[1] = sign < 0 ? '-' : '+';
    if (leni < 10)
    {
        str[2] = '0';
        str[3] = leni + '0';
    }
    else
    {
        str[3] = leni % 10 + '0';
        str[2] = leni / 10 + '0';
    }
    str[4] = '\0';
}

long double prec_for_feg(long double dec, t_print * node)
{
    int i;
    long long remain;
    int counter;

    if (node->precision == 0)
        return (0);
    dec *= dec < 0 ? -1 : 1;
    counter += node->precision + 1;
    dec *= ft_pow(10, counter);
    i = 0;
    counter -= node->precision;
    while (i++ != counter)
    {
        remain = (long long)dec % 10;
        dec /= 10;
        dec += remain > 4 ? 1 : 0;
    }
    return (dec);
}