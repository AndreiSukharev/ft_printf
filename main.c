/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/02/15 16:18:11 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int		main(void)
{

	char *ptr;
	char str[10] = "123";
//	long addr;
//
    ptr = &str[0];
//    addr = (long)str;
//    printf("%p\n", &str);
//
//    printf("|%p|\n", ptr);
//    printf("|%lu|\n", addr);



//    printf("|%*.*s|\n", 6, 3, str);
//	ft_printf("first%-*.*s %%%c=sad", 6, 3, "string", "third");
  ft_printf("address:%p", ptr);

//	printf("|%-5s| |%-5s|", "1", "23");
	return (1);

}
