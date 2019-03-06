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


//long long float_after_point(long double dec, long i)
//{
//    int j;
//    long long tmp;
//
//    j = 0;
//    dec *= dec < 0 ? -1 : 1;
//    tmp = (long long)dec;
//    if (i < 7)
//    {
//        while (j++ <= 7) {
//            if (tmp % 10 == 9) {
//                break;
//            }
//            tmp /= 10;
//        }
//    }
//    dec *= ft_pow(10, i + j);
//    tmp = (long long)dec;
//    while (j-- > 0)
//    {
//        tmp += (tmp % 10) > 0 ? 1 : 0;
//        tmp /= 10;
//    }
//
//    return ((long long)tmp);
//}

long long ft_pow(long long a, int b)
{
    int tmp;

    tmp = (int)a;
    while (--b)
    {
        a *= tmp;
    }
    return (a);
}

void reverse(char *str, int len)
{
    int i=0, j=len-1, temp;
    while (i<j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++; j--;
    }
}

long long intToStr_float(long long x, char str[], int d)
{
    int i;

    i = 0;
    while (x)
    {
        str[i++] = (char)((x % 10) + '0');
        x = x/10;
    }
    str[i++] = '.';
    while (i < d)
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