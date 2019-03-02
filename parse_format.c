/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 15:15:05 by bbashiri          #+#    #+#             */
/*   Updated: 2019/02/16 16:18:11 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strncat_percent(char *restrict s1, const char *restrict s2, t_print *node)
{
    size_t		i;
    size_t		len;

    i = 0;
    len = node->common_len;
    while (s2[i] && i < node->len)
    {
        while (s2[i] == '%' && i < node->len)
        {
            s1[len++] = '%';
            i += 2;
        }
        if (i >= node->len)
            break;
        s1[len] = s2[i];
        i++;
        len++;
    }
    s1[len] = '\0';
    return (s1);
}

size_t    find_percent(const char *str)
{
    size_t i;

    i = 0;
    while (((str[i] != '%') || (str[i] == '%' && str[i + 1] == '%')) && str[i])
    {
        i++;
    }
    return (i);

}

char    *get_str_before_percent(const char *format, t_print *node)
{
    char    *new_str;

    node->len = find_percent(format);
    new_str = ft_strnew(node->len + node->common_len);
    ft_strlcat_all(new_str, node->res, node->common_len);
    new_str = ft_strncat_percent(new_str, format, node);
    ft_strdel(&node->res);
    node->common_len += node->len;
    node->len = 0;
    return (new_str);
}

void rewrite_tprint(t_print *node)
{
    //flag if at the end of function '1', this flag does not exist
    node->flag[0] = '1';
    node->flag[1] = '1';
    node->flag[2] = '1';
    node->flag[3] = '1';
    node->width = -1; // -2 is *
    node->precision = -1; //-3 - tochka, -2 is *
    node->size[0] = '0';
    node->size[1] = '0';
    node->size[2] = '\0';
    node->type = '0'; // if at the end of function '0' it is this flag does not exist
    node->len = 0;
}

void    del_tprint(t_print **node)
{
    free(*node);
    *node = NULL;
}

t_print *init_tprint()
{
    t_print *node;

    if (!(node = (t_print *)malloc(sizeof(t_print))))
        return(NULL);
    //flag if at the end of function '1', this flag does not exist
    node->flag[0] = '1';
    node->flag[1] = '1';
    node->flag[2] = '1';
    node->flag[3] = '1';
    node->width = -1; // -2 is *
    node->precision = -1; //-3 - tochka, -2 is *
    node->size[0] = '0';
    node->size[1] = '0';
    node->size[2] = '\0';
    node->type = '0'; // if at the end of function '0' it is this flag does not exist
    node->len = 0;
    node->common_len = 0;
    node->res = ft_strnew(0);
    node->next_arg = 0;
    return node;
}


