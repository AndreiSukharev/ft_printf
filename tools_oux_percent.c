/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_oux_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/03/11 17:43:51 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_width_after_va(int n, t_print *node)
{
	if (n < 0)
	{
		n *= -1;
		node->flag[0] = '-';
		return (n);
	}
	return (n);
}

int		check_uox(t_print *node, char *arg)
{
	if (node->type == 'p')
		return (1);
	if (node->type == 'o' && node->flag[3] == '#')
	{
		if (arg[0] == '0' || (arg[0] != '0' && node->precision > 0))
			return (0);
		return (1);
	}
	if ((node->type == 'x' || node->type == 'X') && node->flag[3] == '#')
	{
		if (arg[0] == '0')
			return (0);
		return (1);
	}
	return (0);
}

int		check_uox2(t_print *node, char *arg)
{
	if (node->type == 'p')
		return (1);
	if (node->type == 'o')
	{
		if ((arg[0] != '0' || node->flag[3] == '#' || node->precision > 0) ||
			(node->precision == -1 && arg[0] == '0'))
			return (1);
	}
	if (node->type == 'x' || node->type == 'X')
	{
		if (arg[0] != '0' || (arg[0] == '0' && node->precision != 0))
			return (1);
	}
	return (0);
}

void	count_width_oux(t_print *node, char *str_smthto)
{
	int	len;

	len = (int)ft_strlen(str_smthto);
	if (len > node->precision)
		node->len = len;
	else
		node->len = node->precision;
	if (check_uox(node, str_smthto))
		node->len += node->type == 'o' ? 1 : 2;
	if (check_uox2(node, str_smthto) == 0)
		node->len -= 1;
	node->width = node->len > node->width ? node->len : node->width;
}
