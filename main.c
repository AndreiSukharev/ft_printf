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
    char *str[1];

    str[0] = 0;
//    printf("%.2c\n", NULL);
//    ft_printf("%.2c", NULL);

//    printf("%c\n", 42);
//    ft_printf("%c", 42);
    printf("%5c\n", 42);
    ft_printf("%5c", 42);


//    printf("@moulitest: %#.o %#.0o\n", 0, 0);
//    printf("@moulitest: %.x %.0x\n", 0, 0);
//    printf("@moulitest: %5.x %5.0x\n", 0, 0);
//    printf("@moulitest: %.o %.0o\n", 0, 0);
//    printf("@moulitest: %5.o %5.0o\n\n", 0, 0);
//
//    ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
//    ft_printf("@moulitest: %.x %.0x\n", 0, 0);
//    ft_printf("@moulitest: %5.x %5.0x\n", 0, 0);
//    ft_printf("@moulitest: %.o %.0o\n", 0, 0);
//    ft_printf("@moulitest: %5.o %5.0o\n", 0, 0);
//    ft_printf("%s %s", NULL, "string");

//	printf("%#-08x\n", 42);
//	ft_printf("%#-08x\n\n", 42);
//	printf("%#8x\n", 42);
//	ft_printf("%#8x\n\n", 42);
//	printf("%#08x\n", 42);
//	ft_printf("%#08x\n", 42);
//    float f;
//
//    f = 233.2379;
//    printf("%.6Lf\n", f);
//    ft_printf("%.6Lf", f);
//	char *ptr;
//	char str[10] = "123";
//
//	ptr = &str[0];
//	printf("|%+20.10llx| |yegogo%s| |%0hho|\n", -324, "ADD", ptr);
//	ft_printf("|%+20.10llx| |yegogo%s| |%0hho|", -324, "ADD", ptr);
//    printf("|yegogo%s|\n", "ADD");
//    ft_printf("|yegogo%s|", "ADD");
//	printf("|%10.9d|\n", 123456);
//	ft_printf("%10.9d", 123456);


//  think about width, precision in diouxX
//	if it is necessary отделить width, precision from str,char, p


	// printf("%s\n",ft_base_hex((long)ptr, 'p'));
//    printf("|%*.*s|\n", 6, 3, str);
	// ft_printf("first%-*.*s %%%c=sad", 6, 3, "string", "third");

	return (1);

}
