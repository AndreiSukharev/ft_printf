/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:14:50 by bbashiri          #+#    #+#             */
/*   Updated: 2019/02/22 17:22:23 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct  s_print
{
    char        flag;
    int         width;
    int         precision;
    char       *size;
    char        type;
    int         length;
    int         number;

}               t_print;

int             ft_printf(const char * restrict format, ...);

char	        *ft_strncat_percent(char *restrict s1, const char *restrict s2, size_t n);
size_t          find_percent(const char *str);
char            *get_str_before_percent(const char *format, char *old_output);
void            del_tprint(t_print **node);
t_print         *init_tprint(void);
size_t          parse_format(const char *format, t_print *node);

char            check_flag(char format);
int             check_width(const char *format);
int             check_precision(const char *format);
char            *check_size(const char *format);
char            check_type(char format);

char            *parse_str(char *arg, t_print *node);
char            *parse_char(char arg, t_print *node);

char            *parse_address(long address, t_print *node);
char			*ft_base_hex(long n, char type);

#endif
