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

    double n = 55000.56;
//    printf("%#.f\n", n);
//    printf("%#.e\n\n", n);
////    ft_printf("%#.f\n", n);
//    ft_printf("%#.e\n\n", n);

    printf("%g\n", n);
    ft_printf("%g\n", n);

	return (1);

}
