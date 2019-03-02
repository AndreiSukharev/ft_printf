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
//    char *str;


    printf("{%05.*d}\n", -15, 42);
    ft_printf("{%05.*d}", -15, 42);
//    printf("%*.*d\n", 0, 3, 0);
//    printf("{%*3d}\n____\n", 5, 0);
//    ft_printf("%*.*d\n", 0, 3, 0);
//    ft_printf("{%*3d}", 5, 0);
//    printf("%hd%hd\n", (short int)0, (short int)42);
//    printf("%hhi%hhi\n____\n", 0, 42);
//
//    ft_printf("%hd%hd\n", (short int)0, (short int)42);
//    ft_printf("%hhi%hhi\n", 0, 42);

//    ft_printf("%lu", -42);

//    printf("%u\n", 0);
//    printf("%u\n-------\n", 4294967296);
//
//    ft_printf("%u\n", 0);
//    ft_printf("%u\n", 4294967296);
//    printf("%hd\n", -32768);
//    printf("%hd\n", 32768);
//    printf("%hd\n---------\n", -32769);
//
//    ft_printf("%hd\n", -32768);
//    ft_printf("%hd\n", 32768);
//    ft_printf("%hd", -32769);

    //    printf("%-5d\n", -42);
//    printf("%-05d\n\n", -42);
//
//    ft_printf("%-5d\n", -42);
//    ft_printf("%-05d", -42);

//    printf("%-10.5d\n", 4242);
//    printf("%-+10.5d\n", 4242);
//    printf("%10.5d\n", 4242);
//    printf("%-05d\n", -42);
//    printf("%05d\n\n\n", -42);
//
//    ft_printf("%-10.5d\n", 4242);
//    ft_printf("%-+10.5d\n", 4242);
//    ft_printf("%10.5d\n", 4242);
//    ft_printf("%-05d\n", -42);
//    ft_printf("%05d", -42);
//    printf("% d\n", 42);
//
//    ft_printf("% d", 42);

//    printf("@moulitest: %#.o %#.0o\n", 0, 0);
//    printf("@moulitest: %#.x %#.0x\n", 0, 0);
//
//    printf("@moulitest: %.o %.0o|\n", 0, 0);
//    printf("@moulitest: %.x %.0x|\n", 0, 0);
//
//    printf("@moulitest: %5.x %5.0x|\n", 0, 0);
//    printf("@moulitest: %5.o %5.0o|\n\n", 0, 0);
//
//    ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
//    ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
//    ft_printf("@moulitest: %.x %.0x|\n", 0, 0);
//    ft_printf("@moulitest: %5.x %5.0x|\n", 0, 0);
//    ft_printf("@moulitest: %.o %.0o|\n", 0, 0);
//    ft_printf("@moulitest: %5.o %5.0o|\n", 0, 0);

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
