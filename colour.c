/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_addres.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/02/22 17:26:53 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_strequ_l(char const*s1, char *s2, int len)
{
    if (!s1 || !s2)
        return (0);
    while (*s1 && *s1 == *s2 && len)
    {
        s1++;
        s2++;
        len--;
    }
    if (*s1 == *s2)
        return (1);
    return (0);
}

//int add_size_colour(char const *str, int finish)
//{
//    if (ft_strequ_l(str, "{red}", finish))
//        return (0);
//    else if (ft_strequ_l(str, "{green}", finish))
//        return (-2);
//    else if (ft_strequ_l(str, "{yellow}", finish))
//        return (-3);
//    else if (ft_strequ_l(str, "{blue}", finish))
//        return (-1);
//    else if (ft_strequ_l(str, "{magenta}", finish))
//        return (-4);
//    else if (ft_strequ_l(str, "{cyan}", finish))
//        return (-1);
//    else if (ft_strequ_l(str, "{bold}", finish))
//        return (-2);
//    else if (ft_strequ_l(str, "{italic}", finish))
//        return (-4);
//    else if (ft_strequ_l(str, "{underline}", finish))
//        return (-9);
//    else if (ft_strequ_l(str, "{eoc}", finish))
//        return (-1);
//    else
//        return (-10);
//}

int add_size_colour(char const *str, int finish)
{
    if (ft_strequ_l(str, "{red}", finish))
        return (1);
    else if (ft_strequ_l(str, "{green}", finish))
        return (1);
    else if (ft_strequ_l(str, "{yellow}", finish))
        return (1);
    else if (ft_strequ_l(str, "{blue}", finish))
        return (1);
    else if (ft_strequ_l(str, "{magenta}", finish))
        return (1);
    else if (ft_strequ_l(str, "{cyan}", finish))
        return (1);
    else if (ft_strequ_l(str, "{bold}", finish))
        return (1);
    else if (ft_strequ_l(str, "{italic}", finish))
        return (1);
    else if (ft_strequ_l(str, "{underline}", finish))
        return (1);
    else if (ft_strequ_l(str, "{eoc}", finish))
        return (1);
    else
        return (0);
}

int add_colour(char *str, char const *str2, int finish)
{
    int i;

    i = 0;
    if (ft_strequ_l(str2, "{red}", finish))
        i = ft_strlcat_all(str, "\033[31m", 5);
    else if (ft_strequ_l(str2, "{green}", finish))
        i = ft_strlcat_all(str, "\033[32m", 5);
    else if (ft_strequ_l(str2, "{yellow}", finish))
        i = ft_strlcat_all(str, "\033[33m", 5);
    else if (ft_strequ_l(str2, "{blue}", finish))
        i = ft_strlcat_all(str, "\033[34m", 5);
    else if (ft_strequ_l(str2, "{magenta}", finish))
        i = ft_strlcat_all(str, "\033[35m", 5);
    else if (ft_strequ_l(str2, "{cyan}", finish))
        i = ft_strlcat_all(str, "\033[36m", 5);
    else if (ft_strequ_l(str2, "{bold}", finish))
        i = ft_strlcat_all(str, "\033[1m", 4);
    else if (ft_strequ_l(str2, "{italic}", finish))
        i = ft_strlcat_all(str, "\033[3m", 4);
    else if (ft_strequ_l(str2, "{underline}", finish))
        i = ft_strlcat_all(str, "\033[4m", 4);
    else if (ft_strequ_l(str2, "{eoc}", finish))
        i = ft_strlcat_all(str, "\033[0m", 4);
    return (i);
}

//int     find_colour(char const *str2)
//{
//    int start;
//    int finish;
//    int res;
//
//    start = 0;
//    res = 0;
//    while (str2[start] != '%' && str2[start])
//    {
//        while (str2[start] != '{' && str2[start])
//            start++;
//        if (str2[start] != '{')
//            return (res);
//        finish = start;
//        while (str2[finish] != '}' && str2[finish])
//            finish++;
//        if (str2[finish] != '}')
//            return (res);
//        res += add_size_colour(&str2[start], finish - start);
//        finish++;
//        start = finish;
//    }
//    return (res);
//}
int     check_colour(char *str, char const *str2,  char sign)
{
    int start;
    int finish;
    int res;

    start = 0;
    res = 0;
    while (str2[start] != '{' && str2[start])
        start++;
    if (str2[start] != '{')
        return (0);
    finish = start;
    while (str2[finish] != '}' && str2[finish])
        finish++;
    if (str2[finish] != '}')
        return (0);
    if (sign == 'i')
        return (finish + 1);
//    else if (sign == 's')
//        return (find_colour(str2));
//        return (res == -10 ? 0 : res);
    else if (sign == 'c')
        return (add_size_colour(&str2[start], finish - start));
    else if (sign == 'a')
        res = add_colour(str, str2, finish - start);
    return (res);
}


