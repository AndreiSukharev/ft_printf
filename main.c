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
#include <limits.h>

//bonus 10, 52, 79

int		main(void)
{
    char *free;
    free = "sdf";

    printf("%*.*d\n", 0, 3, 0);
    ft_printf("%*.*d", 0, 3, 0);
//    ft_printf("% Z%s", "test");
//    ft_printf("%%%", "test");
//    printf("{%-15Z}\n", 123);
//    ft_printf("{%-15Z}", 123);
//    printf("s: %s, p: %p, d:%d\n", "a string", &free, 42);
//    ft_printf("s: %s, p: %p, d:%d\n", "a string", &free, 42);

	return (1);

}
