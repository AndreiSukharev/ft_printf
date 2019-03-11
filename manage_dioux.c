/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_dioux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/03/11 15:18:41 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*manage_di(char *str_smthto, t_print *node, char sign)
{
	char	*str_width;
	size_t	len_str;
	size_t	padding_prec;

	len_str = ft_strlen(str_smthto);
	node->width = node->len > node->width ? node->len : node->width;
	str_width = ft_strnew(node->width);
	set_width_and_sign_fordi(str_width, node, sign);
	padding_prec = di_precision(str_width, node, node->precision - len_str);
	ft_strcpy_from(str_width, str_smthto, node->flag[0] == '-' ? padding_prec :
		node->width - len_str);
	ft_strdel(&str_smthto);
	return (str_width);
}

char	*manage_uox(char *arg, t_print *node)
{
	char	*str_width;
	int		padding_signs;
	int		padding_prec;

	count_width_oux(node, arg);
	str_width = ft_strnew(node->width);
	ft_strput_width(str_width, node);
	padding_signs = 0;
	if (check_uox(node, arg))
		padding_signs = set_sign_for_pouxx(str_width, node);
	node->len = (int)ft_strlen(arg);
	padding_prec = poux_precision(str_width, node, padding_signs);
	if (check_uox2(node, arg))
		ft_strcpy_from(str_width, arg, (size_t)padding_prec);
	ft_strdel(&arg);
	return (str_width);
}
