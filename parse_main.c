/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/03/11 16:33:40 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*parse_brk(va_list ap, t_print *node)
{
	char *tmp;

	if (node->next_arg == 1)
		va_arg(ap, int);
	if (node->width == -2)
		node->width = check_width_after_va(va_arg(ap, int), node);
	if (node->precision == -2)
		node->precision = va_arg(ap, int);
	if (node->type == 'b')
		tmp = manage_binary(va_arg(ap, long long), node);
	else if (node->type == 'r')
		tmp = manage_nonprint(va_arg(ap, char *), node);
	else
		tmp = NULL;
	return (tmp);
}

char	*parse_csp(va_list ap, t_print *node)
{
	char	*tmp;
	char	*str_s;

	if (node->next_arg == 1)
		va_arg(ap, int);
	if (node->width == -2)
		node->width = check_width_after_va(va_arg(ap, int), node);
	if (node->precision == -2)
		node->precision = va_arg(ap, int);
	if (node->type == 'c')
		tmp = parse_char((char)va_arg(ap, int), node);
	else if (node->type == 's')
	{
		str_s = va_arg(ap, char *);
		if (!str_s)
			tmp = parse_str(ft_strdup("(null)"), node);
		else
			tmp = parse_str(ft_strdup(str_s), node);
	}
	else
		tmp = parse_address(va_arg(ap, long), node);
	return (tmp);
}

char	*parse_dioux_size(va_list ap, t_print *node)
{
	char	*tmp;

	if (node->next_arg == 1)
		va_arg(ap, int);
	if (node->width == -2)
		node->width = check_width_after_va(va_arg(ap, int), node);
	if (node->precision == -2)
		node->precision = va_arg(ap, int);
	if (node->size[1] == 'l' && (node->type == 'd' || node->type == 'i'))
		tmp = manage_longlong(va_arg(ap, long long), node);
	else if (node->size[0] == 'l' && (node->type == 'd' || node->type == 'i'))
		tmp = manage_long(va_arg(ap, long), node);
	else if (node->size[1] == 'h' && (node->type == 'd' || node->type == 'i'))
		tmp = manage_signed_char((signed char)va_arg(ap, int), node);
	else if (node->size[0] == 'h' && (node->type == 'd' || node->type == 'i'))
		tmp = manage_short((short)va_arg(ap, int), node);
	else if (node->size[1] == 'l')
		tmp = manage_unsigned_longlong(va_arg(ap, unsigned long long), node);
	else if (node->size[0] == 'l')
		tmp = manage_unsigned_long(va_arg(ap, unsigned long), node);
	else if (node->size[1] == 'h')
		tmp = manage_unsigned_char((unsigned char)va_arg(ap, int), node);
	else
		tmp = manage_unsigned_short((unsigned short)va_arg(ap, int), node);
	return (tmp);
}

char	*parse_dioux(va_list ap, t_print *node)
{
	char	*tmp;

	if (node->next_arg == 1)
		va_arg(ap, int);
	if (node->width == -2)
		node->width = check_width_after_va(va_arg(ap, int), node);
	if (node->precision == -2)
		node->precision = va_arg(ap, int);
	if (node->type == 'X' || node->type == 'x' || node->type == 'o' ||
		node->type == 'u')
		tmp = manage_unsigned_int(va_arg(ap, unsigned int), node);
	else if (node->type == 'd' || node->type == 'i')
		tmp = manage_int(va_arg(ap, int), node);
	else
		tmp = NULL;
	return (tmp);
}

char	*parse_feg(va_list ap, t_print *node)
{
	char	*tmp;

	if (node->next_arg == 1)
		va_arg(ap, int);
	if (node->width == -2)
		node->width = check_width_after_va(va_arg(ap, int), node);
	if (node->precision == -2)
		node->precision = va_arg(ap, int);
	if (node->size[0] == 'L' && node->type == 'f')
		tmp = manage_double_f(va_arg(ap, long double), node);
	else if (node->type == 'f')
		tmp = manage_double_f(va_arg(ap, double), node);
	else if (node->size[0] == 'L' && node->type == 'e')
		tmp = manage_double_exp(va_arg(ap, long double), node);
	else if (node->type == 'e')
		tmp = manage_double_exp(va_arg(ap, double), node);
	else if (node->size[0] == 'L' && node->type == 'g')
		tmp = manage_double_g(va_arg(ap, long double), node);
	else if (node->type == 'g')
		tmp = manage_double_g(va_arg(ap, double), node);
	else
		tmp = NULL;
	return (tmp);
}
