/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 16:34:56 by mchibane          #+#    #+#             */
/*   Updated: 2021/03/11 18:33:28 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_charset(char c, char *s)
{
	while (*s && s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}

int	is_format(char c)
{
	return (is_charset(c, TYPE_CHARSET)
		|| is_charset(c, FLAGS_CHARSET)
		|| ft_isdigit(c));
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	int		error;

	ret = 0;
	va_start(ap, format);
	while (*format && format)
	{
		if (*format != '%')
			ret += write(1, format++, 1);
		else
		{
			if (is_format(*(++format)) == 1 && format && *format)
			{
				error = format_handler(&format, ap);
				if (error < 0)
					return (-1);
				ret += error;
			}
			else if (*format && format)
				ret += write(1, format++, 1);
		}
	}
	va_end(ap);
	return (ret);
}
