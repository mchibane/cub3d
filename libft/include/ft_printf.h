/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:18:04 by mchibane          #+#    #+#             */
/*   Updated: 2021/03/31 23:26:05 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"
# define TYPE_CHARSET "cspdiuxX"
# define FLAGS_CHARSET "-0.*"
# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"

typedef struct s_format
{
	int	minus;
	int	zero;
	int	dot;
	int	star;
	int	width;
	int	precision;
}				t_format;

int				ft_printf(const char *format, ...);
int				is_charset(char c, char *s);
int				is_format(char c);
int				format_handler(const char **format, va_list ap);
void			fill_struct(t_format *flags, const char **format, va_list ap);
void			padding_handler(char *dst, int len, t_format *flags);
void			int_prec(t_format *flags, char *dst, char *src, int total_len);
void			uint_prec(t_format *flags, char *dst, char *src, int total_len);
int				ft_absolute_len(char *s);
int				get_malloc_size_uint(t_format *flags, char *value,
					int *len, unsigned int uint_value);
int				print_format(char type, t_format *flags, va_list ap);
int				print_string(t_format *flags, char *str);
int				print_percent(t_format *flags);
int				print_char(t_format *flags, int c);
int				print_int(t_format *flags, int value);
int				print_uint(t_format *flags, unsigned int value);
int				print_uint_hex(t_format *flags, unsigned int value, char type);
int				print_uint_ptr(t_format *flags, uintptr_t value);

#endif
