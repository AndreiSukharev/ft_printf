/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/03/11 14:25:59 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_count_short(short n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

size_t	ft_count_signed_char(signed char n)
{
	size_t	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
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

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
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

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}
