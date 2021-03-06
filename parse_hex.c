/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/03/11 16:28:15 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_base_hex(long n)
{
	int		i;
	int		j;
	char	*str;
	int		hex[64];
	char	dict_hex[17];

	ft_strcpy(dict_hex, "0123456789abcdef\0");
	i = 0;
	j = 0;
	while (n)
	{
		hex[i++] = n % 16;
		n /= 16;
	}
	str = ft_strnew(i);
	while (--i >= 0)
		str[j++] = dict_hex[hex[i]];
	return (str);
}

char	*ft_base_xo_longlong(unsigned long long n, char flag, int base)
{
	int		i;
	int		j;
	char	*str;
	int		hex[64];
	char	dict_hex[17];

	if (flag == 'X')
		ft_strcpy(dict_hex, "0123456789ABCDEF\0");
	else
		ft_strcpy(dict_hex, "0123456789abcdef\0");
	i = 0;
	j = 0;
	while (n)
	{
		hex[i++] = n % base;
		n /= base;
	}
	str = ft_strnew(i);
	ft_memset(str, '0', 1);
	while (--i >= 0)
		str[j++] = dict_hex[hex[i]];
	return (str);
}
