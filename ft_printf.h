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

# define ABS(x) (x < 0 ? -x : x)

typedef struct  s_print
{
    char        flag[5];
    int         width;
    int         precision;
    char        size[3];
    char        type;
    int         len;
    size_t      common_len;
    char        *res;
    int         next_arg;
}               t_print;

int             ft_printf(const char * restrict format, ...);
char            *parse_csp(va_list ap, t_print *node);
char            *parse_dioux_size(va_list ap, t_print *node);
char            *parse_dioux(va_list ap, t_print *node);
char            *parse_feg(va_list ap, t_print *node);
char            *parse_brk(va_list ap, t_print *node);

char	        *ft_strncat_percent(char *restrict s1, const char *restrict s2, t_print *node);
size_t          find_percent(const char *str);
char            *get_str_before_percent(const char *format, t_print *node);
void            del_tprint(t_print **node);
t_print         *init_tprint(void);
void            rewrite_tprint(t_print *node);
size_t          parse_format(const char *format, t_print *node);

size_t          check_flag(const char *format, t_print *node);
size_t          check_width(const char *format, t_print *node);
size_t          check_precision(const char *format, t_print *node);
size_t          check_size(const char *format, t_print *node);
size_t          check_type(char format, t_print *node);

char            *parse_str(char *arg, t_print *node);
char            *parse_char(char arg, t_print *node);
char            *parse_address(long, t_print *node);
char            *ft_strcpy_from(char *dst, const char *src, size_t from);

char	        *ft_base_hex(long n);
char	        *ft_base_xo_longlong(unsigned long long n, char flag, int base);

void            set_width_and_sign_ForDI(char * str, t_print *node, char sign);
size_t            di_precision(char *str, t_print *node, int count_zero);
int            set_sign_For_pouxX(char *str, t_print *node);
int       poux_precision(char *str, t_print *node, int padding);

size_t	        ft_count_short(short n);
size_t	        ft_count_signed_char(signed char n);
size_t	        ft_count_long(long n);
size_t	        ft_count_longlong(long long n);

size_t	        ft_count_unsigned_short(unsigned short n);
size_t	        ft_count_unsigned_char(unsigned char n);
size_t	        ft_count_unsigned_int(unsigned int n);
size_t	        ft_count_unsigned_long(unsigned long n);
size_t	        ft_count_unsigned_longlong(unsigned long long n);

char		    *ft_short_toa(short n);
char		    *ft_signed_char_toa(signed char n);
char		    *ft_long_toa(long n);
char		    *ft_longlong_toa(long long n);

char		    *ft_unsigned_short_toa(unsigned short n);
char		    *ft_unsigned_char_toa(unsigned char n);
char		    *ft_unsigned_int_toa(unsigned int n);
char		    *ft_unsigned_long_toa(unsigned long n);
char		    *ft_unsigned_longlong_toa(unsigned long long n);

char            *manage_longlong(long long arg, t_print *node);
char            *manage_long(long arg, t_print *node);
char            *manage_signed_char(signed char arg, t_print *node);
char            *manage_short(short arg, t_print *node);
char            *manage_int(int arg, t_print *node);

char            *manage_unsigned_longlong(unsigned long long arg, t_print *node);
char            *manage_unsigned_long(unsigned long arg, t_print *node);
char            *manage_unsigned_char(unsigned char arg, t_print *node);
char            *manage_unsigned_short(unsigned short arg, t_print *node);
char            *manage_unsigned_int(unsigned int arg, t_print *node);

char            *manage_di(char *str_smthto, t_print *node, char sign);
char            *manage_uox(char *arg, t_print *node);

char            *manage_double_f(long double f, t_print *node);
char            *manage_double_exp(long double f, t_print *node);
char            *manage_double_g(long double f, t_print *node);

long long       ft_pow(long long a, int b);
long long       str_to_float(long long x, char str[], t_print *node);
void            add_exp(char *str, int leni, int sign);
long double     prec_for_feg(long double dec, t_print * node);
int             check_flag_g(t_print *node, long i);

size_t           check_another_percent(const char *format, t_print *node);
int             check_uox(t_print *node, char *str);
int             check_uox2(t_print *node, char *arg);
int             check_width_after_va(int n, t_print * node);
void            count_width_oux(t_print *node, char *str_smthto);
int             check_flag0(t_print *node);


void            ft_strput_width(char *str, t_print * node);
int             ft_strlcat_all(char *restrict dst, const char *restrict src, int size);
char	        *ft_strjoin_all(char *arg, t_print *node);

char            *manage_binary(long long value, t_print *node);
char            *manage_nonprint(char *str, t_print *node);
int             check_colour(char *str, char const *str2,  char sign);


#endif
