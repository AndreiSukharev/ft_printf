/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_feg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/03/11 15:44:48 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_float(char *str_smthto, t_print *node)
{
	char	*str_width;
	char	*dup;
	char	sign;

	node->precision = -1;
	sign = get_sign(str_smthto[0], node);
	node->len = ft_strlen(str_smthto) + (sign != '0' &&
		str_smthto[0] != '-' ? 1 : 0);
	node->width = node->len > node->width ? node->len : node->width;
	str_width = ft_strnew(node->width);
	set_width_and_sign_fordi(str_width, node, sign);
	sign = sign == '0' ? 0 : 1;
	if (str_smthto[0] == '-')
	{
		dup = ft_strdup(&str_smthto[1]);
		ft_strcpy_from(str_width, dup, node->flag[0] == '-' ? 1 : node->width -
			node->len + 1);
		ft_strdel(&dup);
	}
	else
		ft_strcpy_from(str_width, str_smthto, node->flag[0] == '-' ? sign :
			node->width - node->len + sign);
	ft_strdel(&str_smthto);
	return (str_width);
}

char	*combine_floats(long i, long double dec, t_print *node)
{
	char	*int_part;
	char	*nul_str;
	char	*dec_part;
	char	*res;

	if (i == 0 && dec < 0)
	{
		nul_str = ft_long_toa(i);
		int_part = ft_strjoin("-", nul_str);
		ft_strdel(&nul_str);
	}
	else
		int_part = ft_long_toa(i);
	node->precision = node->precision == -1 ? 6 : node->precision;
	dec = prec_for_feg(dec, node);
	dec_part = ft_strnew(ft_count_longlong((long long)dec) + 1 + (node->type ==
		'e' ? 2 + ABS(node->len) : 0));
	i = str_to_float((long long)dec, dec_part, node);
	if (node->type == 'e')
		add_exp(&dec_part[i], ABS(node->len), node->len);
	res = ft_strjoin(int_part, dec_part);
	ft_strdel(&dec_part);
	ft_strdel(&int_part);
	return (add_float(res, node));
}

char	*manage_double_f(long double f, t_print *node)
{
	long		i;
	long double	dec;
	int			tmp;

	if (f == 0)
		return (long_double0(node));
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

char	*manage_double_exp(long double f, t_print *node)
{
	if (f == 0)
		return (long_double0(node));
	if (f < 1 && f > -1)
		return (manage_double_exp_less_1(f, node));
	else
		return (manage_double_exp_more_1(f, node));
}

char	*manage_double_g(long double f, t_print *node)
{
	char	*res;
	long	i;
	int		index;

	if (f == 0)
		return (long_double0(node));
	i = (long)f;
	index = 0;
	node->len = ft_count_long(i) - (i < 0 ? 1 : 0);
	if (check_flag_g(node, i))
	{
		res = manage_double_f(f, node);
		while (res[index] && res[index] != '.')
			index++;
		while (res[index] && res[index] != '0')
			index++;
		res[index] = '\0';
	}
	else
		res = manage_double_exp(f, node);
	return (res);
}
