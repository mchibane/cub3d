/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 11:46:37 by mchibane          #+#    #+#             */
/*   Updated: 2021/03/22 21:18:55 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_format_len(const char *format)
{
	int	i;

	i = 0;
	while (is_charset(format[i], TYPE_CHARSET) == 0 && format[i] != '%')
		i++;
	return (i);
}

int	format_handler(const char **format, va_list ap)
{
	int			ret;
	t_format	flags;

	ret = 0;
	ft_bzero(&flags, sizeof(flags));
	fill_struct(&flags, format, ap);
	if (is_charset(**format, TYPE_CHARSET) || is_charset(**format, "%"))
	{
		ret += print_format(**format, &flags, ap);
		*(format) += get_format_len(*format) + 1;
	}
	else
		return (-1);
	return (ret);
}
