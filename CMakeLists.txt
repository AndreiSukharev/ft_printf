cmake_minimum_required (VERSION 2.6)
project (make-build-debug/ft_printf)
set(SOURCE_FILES ft_printf.h main.c ft_printf.c check_format.c manage_csp.c parse_hex.c manage_dioux.c flags_dioux.c count.c count_unsigned.c smth_to_a.c smth_un_to_a.c manage_unsigned_size.c manage_size.c parse_main.c manage_feg.c libfeg.c libfeg2.c str.c bonus_flags_brk.c colour.c get_str_before_perc.c t_print.c tools_format_flag.c tools_oux_percent.c)
add_executable(make-build-debug/ft_printf ${SOURCE_FILES})
target_link_libraries(make-build-debug/ft_printf /Users/andrei/hack/school42/ft_printf/libft.a)
