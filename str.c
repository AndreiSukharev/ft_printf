/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/03/11 16:47:17 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strput_width(char *str, t_print *node)
{
	if (check_flag0(node) && (node->type != 'c' && node->type != 's'))
		ft_memset(str, '0', node->width);
	else if (node->flag[4] == '0' && node->flag[0] != '-' &&
		(node->type == 'c' || node->type == 's' || node->type == '0'))
		ft_memset(str, '0', node->width);
	else
		ft_memset(str, ' ', node->width);
}

int		ft_strlcat_all(char *restrict dst, const char *restrict src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

char	*ft_strjoin_all(char *arg, t_print *node)
{
	char	*str;
	int		len;

	if (!node->res || !arg)
		return (0);
	str = ft_memalloc(node->common_len + 1);
	if (!str)
		return (NULL);
	len = (int)ft_strlen(node->res);
	ft_strlcat_all(str, node->res, len);
	ft_strlcat_all(&str[len], arg, (int)node->common_len - len);
	ft_strdel(&node->res);
	return (str);
}
