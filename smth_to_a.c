/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/02/22 17:26:53 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_short_toa(short n)
{
    char	*str;
    int		len;
    int		sign;

    len = ft_count_short(n);
    str = ft_strnew(len);
    if (!str)
        return (0);
    sign = n < 0 ? 1 : 0;
    if (n < 0)
        n *= -1;
    while (len >= 0)
    {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    if (sign == 1)
        str[0] = '-';
    return (str);
}

char		*ft_signed_char_toa(signed char n)
{
    char	*str;
    int		len;
    int		sign;

    len = ft_count_signed_char(n);
    str = ft_strnew(len);
    if (!str)
        return (0);
    sign = n < 0 ? 1 : 0;
    if (n < 0)
        n *= -1;
    while (len >= 0)
    {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    if (sign == 1)
        str[0] = '-';
    return (str);
}

char		*ft_long_toa(long n)
{
    char	*str;
    int		len;
    int		sign;

    len = ft_count_long(n);
    str = ft_strnew(len);
    if (!str)
        return (0);
    sign = n < 0 ? 1 : 0;
    if (n < 0)
        n *= -1;
    while (len >= 0)
    {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    if (sign == 1)
        str[0] = '-';
    return (str);
}

char		*ft_longlong_toa(long long n)
{
    char	*str;
    int		len;
    int		sign;

    len = ft_count_longlong(n);
    str = ft_strnew(len);
    if (!str)
        return (0);
    sign = n < 0 ? 1 : 0;
    if (n < 0)
        n *= -1;
    while (len >= 0)
    {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    if (sign == 1)
        str[0] = '-';
    return (str);
}