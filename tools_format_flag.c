/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_format_flag.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/03/11 17:33:58 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_sign_for_pouxx_tool(char *str, t_print *node, int index)
{
	if (node->type == 'p' || (node->flag[3] == '#' && (node->type == 'x' ||
		node->type == 'X')))
	{
		str[index] = '0';
		str[++index] = (char)(node->type == 'X' ? 'X' : 'x');
	}
	else if (node->flag[3] == '#' && node->type == 'o')
		str[index] = '0';
	return (index);
}

int	check_width_tool(char format, t_print *node)
{
	if (format == '*')
	{
		node->width = -2;
		return (1);
	}
	return (0);
}

int	check_precision_tool(char format, int precision)
{
	if (format == '*')
		return (-2);
	return (precision);
}

int	check_size_tool(char const *format, t_print *node, int i)
{
	node->size[0] = 'l';
	if (format[i + 1] == 'l')
	{
		node->size[1] = 'l';
		return (1);
	}
	return (0);
}
