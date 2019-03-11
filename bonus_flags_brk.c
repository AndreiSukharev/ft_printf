/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_flags_brk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/03/11 13:38:56 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_bit(char *str, long long bit, long long value)
{
	int	i;

	i = 0;
	while (bit)
	{
		if (bit & value)
			str[i++] = '1';
		else
			str[i++] = '0';
		bit >>= 1;
	}
}

char	*manage_binary(long long value, t_print *node)
{
	long long	bit;
	char		*str;
	int			i;

	i = 0;
	bit = 1;
	value *= value < 0 ? -1 + 1 : 1;
	while (bit < value)
	{
		bit *= 2;
		i++;
	}
	if (bit > value)
	{
		bit /= 2;
		i--;
	}
	str = ft_strnew(i);
	get_bit(str, bit, value);
	return (parse_str(str, node));
}

void	add_nonprint(char *str, char *res, char const *dict_nonprint)
{
	int		i;
	char	*hex;

	i = 0;
	while (*str)
	{
		if (ft_isprint(*str))
			res[i++] = *str;
		else
		{
			res[i++] = '\\';
			if (*str <= 13 && *str > 6)
				res[i++] = dict_nonprint[*str];
			else
			{
				hex = ft_base_xo_longlong(*str, 'X', 16);
				res[i++] = 'x';
				if (ft_strlen(hex) == 1)
					res[i++] = '0';
				while (*hex)
					res[i++] = *hex++;
			}
		}
		str++;
	}
}

char	*manage_nonprint(char *str, t_print *node)
{
	char	dict_nonprint[15];
	char	*res;

	ft_strcpy(dict_nonprint, "0123456abtnvfr\0");
	res = ft_strnew(ft_strlen(str) * 4);
	add_nonprint(str, res, dict_nonprint);
	return (parse_str(res, node));
}
