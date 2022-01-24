/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 11:14:02 by mchibane          #+#    #+#             */
/*   Updated: 2021/03/31 21:46:54 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_base(unsigned int value, char type)
{
	char	*str;

	str = NULL;
	if (type == 'x')
		str = ft_uitoa_base(value, HEX_LOWER);
	else if (type == 'X')
		str = ft_uitoa_base(value, HEX_UPPER);
	return (str);
}

int	print_uint_hex(t_format *flags, unsigned int value, char type)
{
	int		ret;
	char	*print;
	char	*str;
	int		size;
	int		len;

	len = 0;
	str = get_base(value, type);
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
