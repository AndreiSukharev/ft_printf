/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_unsigned_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/03/11 15:55:10 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*manage_unsigned_longlong(unsigned long long arg, t_print *node)
{
	char	*str_smthto;
	int		count;

	if (node->type == 'u')
	{
		str_smthto = ft_unsigned_longlong_toa(arg);
		if (str_smthto[0] == '0' && node->precision == 0)
		{
			ft_strdel(&str_smthto);
			return (parse_str(ft_strdup(""), node));
		}
		count = ft_strlen(str_smthto);
		node->len = node->precision > count ? node->precision : count;
		return (manage_di(str_smthto, node, '0'));
	}
	str_smthto = ft_base_xo_longlong(arg, node->type, node->type == 'o' ?
		8 : 16);
	return (manage_uox(str_smthto, node));
}

char	*manage_unsigned_long(unsigned long arg, t_print *node)
{
	char	*str_smthto;
	int		count;

	if (node->type == 'u')
	{
		str_smthto = ft_unsigned_long_toa(arg);
		if (str_smthto[0] == '0' && node->precision == 0)
		{
			ft_strdel(&str_smthto);
			return (parse_str(ft_strdup(""), node));
		}
		count = ft_strlen(str_smthto);
		node->len = node->precision > count ? node->precision : count;
		return (manage_di(str_smthto, node, '0'));
	}
	str_smthto = ft_base_xo_longlong(arg, node->type, node->type == 'o' ?
		8 : 16);
	return (manage_uox(str_smthto, node));
}

char	*manage_unsigned_char(unsigned char arg, t_print *node)
{
	char	*str_smthto;
	int		count;

	if (node->type == 'u')
	{
		str_smthto = ft_unsigned_char_toa(arg);
		if (str_smthto[0] == '0' && node->precision == 0)
		{
			ft_strdel(&str_smthto);
			return (parse_str(ft_strdup(""), node));
		}
		count = ft_strlen(str_smthto);
		node->len = node->precision > count ? node->precision : count;
		return (manage_di(str_smthto, node, '0'));
	}
	str_smthto = ft_base_xo_longlong(arg, node->type, node->type == 'o' ?
		8 : 16);
	return (manage_uox(str_smthto, node));
}

char	*manage_unsigned_short(unsigned short arg, t_print *node)
{
	char	*str_smthto;
	int		count;

	if (node->type == 'u')
	{
		str_smthto = ft_unsigned_short_toa(arg);
		if (str_smthto[0] == '0' && node->precision == 0)
		{
			ft_strdel(&str_smthto);
			return (parse_str(ft_strdup(""), node));
		}
		count = ft_strlen(str_smthto);
		node->len = node->precision > count ? node->precision : count;
		return (manage_di(str_smthto, node, '0'));
	}
	str_smthto = ft_base_xo_longlong(arg, node->type, node->type == 'o' ?
		8 : 16);
	return (manage_uox(str_smthto, node));
}

char	*manage_unsigned_int(unsigned int arg, t_print *node)
{
	char	*str_smthto;
	int		count;

	if (node->type == 'u')
	{
		str_smthto = ft_unsigned_int_toa(arg);
		if (str_smthto[0] == '0' && node->precision == 0)
		{
			ft_strdel(&str_smthto);
			return (parse_str(ft_strdup(""), node));
		}
		count = ft_strlen(str_smthto);
		node->len = node->precision > count ? node->precision : count;
		return (manage_di(str_smthto, node, '0'));
	}
	str_smthto = ft_base_xo_longlong(arg, node->type, node->type == 'o' ?
		8 : 16);
	return (manage_uox(str_smthto, node));
}
