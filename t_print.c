/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_print.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/03/11 16:17:07 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rewrite_tprint(t_print *node)
{
	node->flag[0] = '1';
	node->flag[1] = '1';
	node->flag[2] = '1';
	node->flag[3] = '1';
	node->width = 0;
	node->precision = -1;
	node->size[0] = '0';
	node->size[1] = '0';
	node->size[2] = '\0';
	node->type = '0';
	node->len = 0;
	node->next_arg = 0;
}

void	del_tprint(t_print **node)
{
	free(*node);
	*node = NULL;
}

t_print	*init_tprint(void)
{
	t_print *node;

	if (!(node = (t_print *)malloc(sizeof(t_print))))
		return (NULL);
	node->flag[0] = '1';
	node->flag[1] = '1';
	node->flag[2] = '1';
	node->flag[3] = '1';
	node->flag[3] = '\0';
	node->width = 0;
	node->precision = -1;
	node->size[0] = '0';
	node->size[1] = '0';
	node->size[2] = '\0';
	node->type = '0';
	node->len = 0;
	node->common_len = 0;
	node->res = ft_strnew(0);
	node->next_arg = 0;
	return (node);
}
