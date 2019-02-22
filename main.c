/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/02/22 17:27:24 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{

	char *ptr;
	char str[10] = "123";

	ptr = &str[0];
	printf("%p\n", ptr);
	ft_printf("%p", ptr);
	// printf("%s\n",ft_base_hex((long)ptr, 'p'));
//    printf("|%*.*s|\n", 6, 3, str);
	// ft_printf("first%-*.*s %%%c=sad", 6, 3, "string", "third");

	return (1);

}
