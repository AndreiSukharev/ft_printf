/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_addres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/02/22 17:26:53 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_base_hex(long n, char type)
{
	int			i;
	int			j;
	char		*str;
	int			hex[64];
	char 		dict_hex[16];

	if (type == 'X')
		ft_strcpy(dict_hex, "0123456789ABCDEF");
	else
		ft_strcpy(dict_hex, "0123456789abcdef");
	i = 0;
	j = 2;
	while (n)
	{
		hex[i++] = n % 16;
		n /= 16;
	}
	str = ft_strnew(i + 2);
	str[0] = '0';
	str[1] = 'x';
	while (--i >= 0)
		str[j++] = dict_hex[hex[i]];
	return (str);
}

// static size_t	ft_countlong(long n)
// {
// 	size_t	count;
//
// 	if (n < 1)
// 		return (0);
// 	count = 0;
// 	while (n)
// 	{
// 		n /= 10;
// 		count++;
// 	}
// 	return (count);
// }

char *parse_address(long address, t_print *node)
{
    char *str;

    str = ft_base_hex(address, node->type);
    return (str);
}
