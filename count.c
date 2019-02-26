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

size_t	 ft_count_short(short n)
{
    size_t	count;

    if (n < 1)
        return (0);
    count = 0;
    while (n)
    {
        n /= 10;
        count++;
    }
    return (count);
}

size_t	 ft_count_signed_char(signed char n)
{
    size_t	count;

    if (n < 1)
        return (0);
    count = 0;
    while (n)
    {
        n /= 10;
        count++;
    }
    return (count);
}


size_t	ft_count_long(long n)
{
    size_t	count;

    if (n < 1)
        return (0);
    count = 0;
    while (n)
    {
        n /= 10;
        count++;
    }
    return (count);
}

size_t	ft_count_longlong(long long n)
{
    size_t	count;

    if (n < 1)
        return (0);
    count = 0;
    while (n)
    {
        n /= 10;
        count++;
    }
    return (count);
}
