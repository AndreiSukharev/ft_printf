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



unsigned char	reverse_bits(unsigned char octet)
{
    int				i;
    unsigned char	last;
    unsigned char	reversed;

    i = 0;
    while (i < 7)
    {
        last = octet & 1;
        octet >>= 1;
        reversed += last;
        reversed <<= 1;
        i++;
    }
    return (reversed);
}

void		print_bits(unsigned char octet)
{
    int	i;

    i = 128;
    while (i > 0)
    {
        if (i & octet)
            write(1, "1", 1);
        else
            write(1, "0", 1);
        i >>= 1;
    }
}

unsigned char	swap_bits(unsigned char octet)
{
    return (octet >> 4 | octet << 4);
}

int		main(void)
{
    char *free;
    free = "sdf";
    double n = -0.688878;
    char* charactersA4 = "\n" "213";
    
//    ft_printf("%10r", charactersA4);
//    print_bits(((unsigned char)12346));
//    ft_printf("\033[35m");
//    printf("Le fichier\033[0;34m%s\033[0;35m contient : \033[0;36m%s{eoc}", "sadasd", "asdasd");
//    printf("Le{red}%s{test} cont {green}%s\n", "first", "second");
//    ft_printf("Le {cyan}%s{eoc} con: {red}%s{eoc}", "first", "second");
    printf("s: %s, p: %p, d:%d\n", "a string", &free, 42);
    ft_printf("s: %s, p: %p, d:%d", "a string", &free, 42);
	return (1);

}
