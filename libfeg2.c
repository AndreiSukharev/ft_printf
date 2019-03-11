/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfeg2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/03/11 15:44:56 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_sign(char str_smthto, t_print *node)
{
	if (str_smthto == '-')
		return ('-');
	else if (node->flag[1] == '+')
		return ('+');
	else if (node->flag[2] == ' ')
		return (' ');
	return ('0');
}

char	*long_double0(t_print *node)
{
	char	*dec_part;
	char	*res;

	node->precision = node->precision == -1 ? 6 : node->precision;
	dec_part = ft_strnew(node->precision + (node->type == 'e' ?
		2 + node->len : 0));
	ft_memset(dec_part, '0', node->precision);
	if (node->type == 'e')
		add_exp(&dec_part[node->precision], 0, 0);
	if (node->precision == 0)
		res = ft_strjoin("0", dec_part);
	else
		res = ft_strjoin("0.", dec_part);
	ft_strdel(&dec_part);
	return (add_float(res, node));
}

char	*manage_double_exp_less_1(long double f, t_print *node)
{
	long		i;
	long double	dec;
	int			tmp;

	while ((long)f == 0)
	{
		f *= 10;
		node->len += 1;
	}
	node->len *= -1;
	i = (long)f;
	dec = f - i;
	if (node->precision == 0)
	{
		tmp = dec * 10;
		if (ABS(tmp) > 4)
			i = (dec < 0 ? i - 1 : i + 1);
	}
	return (combine_floats(i, dec, node));
}

char	*manage_double_exp_more_1(long double f, t_print *node)
{
	long		i;
	long double	dec;
	long		pow_i;
	int			tmp;

	i = (long)f;
	node->len = ft_count_long(i);
	if (i < 0)
		node->len -= 1;
	if (node->len > 1)
	{
		pow_i = ft_pow(10, node->len - 1);
		i /= pow_i;
		dec = (f - i * ft_pow(10, node->len - 1)) /
			ft_pow(10, node->len - 1);
		tmp = dec * 10;
		if (ABS(tmp) > 4 && node->precision == 0)
			i = (dec < 0 ? i - 1 : i + 1);
	}
	else
		dec = f - i;
	node->len -= 1;
	return (combine_floats(i, dec, node));
}
