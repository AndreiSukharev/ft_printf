/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_before_perc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/03/11 17:43:56 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	check_another_percent(const char *format, t_print *node)
{
	char	*str;
	size_t	index_percent;
	size_t	i;
	char	*tmp;

	i = 0;
	if (format[0] == 0)
		return (0);
	str = parse_char(format[0], node);
	node->common_len += ft_strlen(str);
	node->res = ft_strjoin_all(str, node);
	ft_strdel(&str);
	return (1);
}

char	*ft_strncat_percent(char *s1, const char *s2, t_print *node)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = node->common_len;
	while (s2[i] && i < node->len)
	{
		if (s2[i] == '{' && check_colour("test", &s2[i], 'c'))
		{
			len += check_colour(&s1[len], &s2[i], 'a');
			i += check_colour("test", &s2[i], 'i');
		}
		while (s2[i] == '%' && i < node->len)
		{
			s1[len++] = '%';
			i += 2;
		}
		if (i >= node->len)
			break ;
		s1[len++] = s2[i++];
	}
	s1[len] = '\0';
	node->common_len = len;
	return (s1);
}

size_t	find_percent(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == '%' && str[i + 1] == '%')
		{
			i += 2;
		}
		if (str[i] == '%' || !str[i])
			return (i);
		i++;
	}
	return (i);
}

char	*get_str_before_percent(const char *format, t_print *node)
{
	char	*new_str;

	node->len = find_percent(format);
	new_str = ft_strnew(node->len + node->common_len);
	ft_strlcat_all(new_str, node->res, node->common_len);
	new_str = ft_strncat_percent(new_str, format, node);
	ft_strdel(&node->res);
	node->len = 0;
	return (new_str);
}
