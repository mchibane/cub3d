/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:25:36 by mchibane          #+#    #+#             */
/*   Updated: 2021/03/31 21:49:57 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_malloc_size_uint(t_format *flags, char *value,
		int *len, unsigned int uint_value)
{
	int	ret;

	ret = 0;
	*len = ft_strlen(value);
	if (uint_value == 0 && flags->dot == 1 && flags->precision == 0)
		*len = 0;
	if (flags->dot == 1 && flags->precision > *len)
		*len = (flags->precision);
	if (flags->width > *len)
		ret = flags->width;
	else
		ret = *len;
	if (flags->dot == 1)
		flags->zero = 0;
	return (ret);
}

int	print_uint(t_format *flags, unsigned int value)
{
	int		ret;
	char	*print;
	char	*str;
	int		size;
	int		len;

	len = 0;
	str = ft_uitoa(value);
	size = get_malloc_size_uint(flags, str, &len, value);
	print = malloc(sizeof(*print) * (size + 1));
	if (!print)
		return (-1);
	print[size] = 0;
	padding_handler(print, len, flags);
	uint_prec(flags, print, str, len);
	ft_putstr_fd(print, 1);
	ret = ft_strlen(print);
	free(str);
	free(print);
	return (ret);
}
