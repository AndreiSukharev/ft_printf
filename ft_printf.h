/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:14:50 by bbashiri          #+#    #+#             */
/*   Updated: 2019/03/11 17:43:40 by bbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define ABS(x) (x < 0 ? -x : x)

typedef struct	s_print
{
	char		flag[5];
	int			width;
	int			precision;
	char		size[3];
	char		type;
	int			len;
	size_t		common_len;
	char		*res;
	int			next_arg;
}				t_print;

/*
*****************************ft_printf.c***************************************
*/
int				ft_printf(const char *restrict format, ...);

/*
*****************************parse_main.c**************************************
*/
char			*parse_brk(va_list ap, t_print *node);
char			*parse_csp(va_list ap, t_print *node);
char			*parse_dioux_size(va_list ap, t_print *node);
char			*parse_dioux(va_list ap, t_print *node);
char			*parse_feg(va_list ap, t_print *node);

/*
********************get_str_before_perc.c**************************************
*/
size_t			check_another_percent(const char *format, t_print *node);
char			*ft_strncat_percent(char *s1, const char *s2, t_print *node);
size_t			find_percent(const char *str);
char			*get_str_before_percent(const char *format, t_print *node);

/*
*****************************t_print.c*****************************************
*/
void			rewrite_tprint(t_print *node);
void			del_tprint(t_print **node);
t_print			*init_tprint(void);

/*
*****************************check_format.c************************************
*/
size_t			check_flag(const char *format, t_print *node);
size_t			check_width(const char *format, t_print *node);
size_t			check_precision(const char *format, t_print *node);
size_t			check_size(const char *format, t_print *node);
size_t			check_type(char format, t_print *node);

/*
*****************************manage_csp.c**************************************
*/
char			*ft_strcpy_from(char *dst, const char *src, size_t from);
char			*parse_str(char *arg, t_print *node);
char			*parse_char(char arg, t_print *node);
char			*parse_address(long address, t_print *node);

/*
*****************************parse_hex.c**************************************
*/
char			*ft_base_hex(long n);
char			*ft_base_xo_longlong(unsigned long long n, char flag, int base);

/*
*****************************flags_dioux.c************************************
*/
int				check_flag0(t_print *node);
void			set_width_and_sign_fordi(char *str, t_print *node, char sign);
size_t			di_precision(char *str, t_print *node, int count_zero);
int				set_sign_for_pouxx(char *str, t_print *node);
int				poux_precision(char *str, t_print *node, int padding);

/*
*****************************count.c******************************************
*/
size_t			ft_count_short(short n);
size_t			ft_count_signed_char(signed char n);
size_t			ft_count_long(long n);
size_t			ft_count_longlong(long long n);

/*
********************count_unsighned.c******************************************
*/
size_t			ft_count_unsigned_short(unsigned short n);
size_t			ft_count_unsigned_char(unsigned char n);
size_t			ft_count_unsigned_int(unsigned int n);
size_t			ft_count_unsigned_long(unsigned long n);
size_t			ft_count_unsigned_longlong(unsigned long long n);

/*
********************smth_to_a.c************************************************
*/
char			*ft_short_toa(short n);
char			*ft_signed_char_toa(signed char n);
char			*ft_long_toa(long n);
char			*ft_longlong_toa(long long n);

/*
********************smth_un_to_a.c*********************************************
*/
char			*ft_unsigned_short_toa(unsigned short n);
char			*ft_unsigned_char_toa(unsigned char n);
char			*ft_unsigned_int_toa(unsigned int n);
char			*ft_unsigned_long_toa(unsigned long n);
char			*ft_unsigned_longlong_toa(unsigned long long n);

/*
********************manage_size.c*********************************************
*/
char			*manage_longlong(long long arg, t_print *node);
char			*manage_long(long arg, t_print *node);
char			*manage_signed_char(signed char arg, t_print *node);
char			*manage_short(short arg, t_print *node);
char			*manage_int(int arg, t_print *node);

/*
********************manage_unsigned_size.c*************************************
*/
char			*manage_unsigned_longlong(unsigned long long arg,
				t_print *node);
char			*manage_unsigned_long(unsigned long arg, t_print *node);
char			*manage_unsigned_char(unsigned char arg, t_print *node);
char			*manage_unsigned_short(unsigned short arg, t_print *node);
char			*manage_unsigned_int(unsigned int arg, t_print *node);

/*
********************manage_dioux.c*********************************************
*/
char			*manage_di(char *str_smthto, t_print *node, char sign);
char			*manage_uox(char *arg, t_print *node);

/*
********************manage_feg.c*********************************************
*/
char			*add_float(char *str_smthto, t_print *node);
char			*combine_floats(long i, long double dec, t_print *node);
char			*manage_double_f(long double f, t_print *node);
char			*manage_double_exp(long double f, t_print *node);
char			*manage_double_g(long double f, t_print *node);

/*
*****************************str.c********************************************
*/
void			ft_strput_width(char *str, t_print *node);
int				ft_strlcat_all(char *restrict dst, const char *restrict src,
				int size);
char			*ft_strjoin_all(char *arg, t_print *node);

/*
************************bonus_flags_brk.c**************************************
*/
char			*manage_binary(long long value, t_print *node);
char			*manage_nonprint(char *str, t_print *node);

/*
*****************************colour.c******************************************
*/
int				check_colour(char *str, char const *str2, char sign);

/*
********************libfeg.c*********************************************
*/
int				check_flag_g(t_print *node, long i);
long long		str_to_float(long long x, char str[], t_print *node);
void			add_exp(char *str, int leni, int sign);
long double		prec_for_feg(long double dec, t_print *node);
long long		ft_pow(long long a, int b);

/*
********************libfeg2.c*********************************************
*/
char			get_sign(char str_smthto, t_print *node);
char			*long_double0(t_print *node);
char			*manage_double_exp_less_1(long double f, t_print *node);
char			*manage_double_exp_more_1(long double f, t_print *node);

/*
********************tools_oux_percent.c*************************************
*/
int				check_width_after_va(int n, t_print *node);
int				check_uox(t_print *node, char *str);
int				check_uox2(t_print *node, char *arg);
void			count_width_oux(t_print *node, char *str_smthto);

/*
**********************tools_format_flag.c**************************************
*/
int				set_sign_for_pouxx_tool(char *str, t_print *node, int index);
int				check_width_tool(char format, t_print *node);
int				check_precision_tool(char format, int precision);
int				check_size_tool(char const *format, t_print *node, int i);

#endif
