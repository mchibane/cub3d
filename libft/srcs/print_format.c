/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 11:33:06 by mchibane          #+#    #+#             */
/*   Updated: 2021/03/31 23:26:08 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char type, t_format *flags, va_list ap)
{
	int	ret;

	ret = 0;
	if (type == 's')
		ret = print_string(flags, va_arg(ap, char *));
	else if (type == '%')
		ret = print_percent(flags);
	else if (type == 'c')
		ret = print_char(flags, va_arg(ap, int));
	else if (type == 'd' || type == 'i')
		ret = print_int(flags, va_arg(ap, int));
	else if (type == 'u')
		ret = print_uint(flags, (unsigned int)va_arg(ap, unsigned int));
	else if (type == 'x' || type == 'X')
		ret = print_uint_hex(flags,
				(unsigned int)va_arg(ap, unsigned int), type);
	else if (type == 'p')
		ret = print_uint_ptr(flags, (uintptr_t)va_arg(ap, uintptr_t));
	return (ret);
}
