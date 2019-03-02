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

char		*ft_unsigned_short_toa(unsigned short n)
{
    char	*str;
    int		len;

    if (!str)
        return (0);
    if (n == 0)
        return (ft_strdup("0"));
    len = ft_count_unsigned_short(n);
    str = ft_strnew(len);
    while (len >= 0)
    {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    return (str);
}

char		*ft_unsigned_char_toa(unsigned char n)
{
    char	*str;
    int		len;

    if (!str)
        return (0);
    if (n == 0)
        return (ft_strdup("0"));
    len = ft_count_unsigned_char(n);
    str = ft_strnew(len);
    while (len >= 0)
    {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    return (str);
}

char		*ft_unsigned_int_toa(unsigned int n)
{
    char	*str;
    int		len;

    if (!str)
        return (0);
    if (n == 0)
        return (ft_strdup("0"));
    len = ft_count_unsigned_int(n);
    str = ft_strnew(len);
    while (len >= 0)
    {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    return (str);
}

char		*ft_unsigned_long_toa(unsigned long n)
{
    char	*str;
    int		len;

    if (!str)
        return (0);
    if (n == 0)
        return (ft_strdup("0"));
    len = ft_count_unsigned_long(n);
    str = ft_strnew(len);
    while (len >= 0)
    {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    return (str);
}


char		*ft_unsigned_longlong_toa(unsigned long long n)
{
    char	*str;
    int		len;

    if (!str)
        return (0);
    if (n == 0)
        return (ft_strdup("0"));
    len = ft_count_unsigned_longlong(n);
    str = ft_strnew(len);
    while (len >= 0)
    {
        str[--len] = (n % 10) + '0';
        n /= 10;
    }
    return (str);
}