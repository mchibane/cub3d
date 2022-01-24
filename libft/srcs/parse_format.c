/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:32:09 by mchibane          #+#    #+#             */
/*   Updated: 2021/03/24 13:02:55 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	set_flags(const char **format, t_format *flags)
{
	while (is_charset(**format, "-0"))
	{
		if (**format == '0')
			flags->zero = 1;
		if (**format == '-')
			flags->minus = 1;
		(*format)++;
	}
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = 0;
}

static void	set_width(const char **format, t_format *flags, va_list ap)
{
	if (**format == '*')
	{
		flags->star = 1;
		flags->width = va_arg(ap, int);
		(*format)++;
	}
	else if (ft_isdigit(**format))
		flags->width = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
	if (flags->width < 0)
	{
		flags->minus = 1;
		flags->zero = 0;
		flags->width *= -1;
	}
}

static void	set_precision(const char **format, t_format *flags, va_list ap)
{
	if (**format == '.')
	{
		flags->dot = 1;
		(*format)++;
		if (**format == '*')
		{
			flags->star = 1;
			flags->precision = va_arg(ap, int);
			(*format)++;
		}
		else if (ft_isdigit(**format))
			flags->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	if (flags->precision < 0)
		flags->dot = 0;
}

void	fill_struct(t_format *flags, const char **format, va_list ap)
{
	set_flags(format, flags);
	set_width(format, flags, ap);
	set_precision(format, flags, ap);
}
