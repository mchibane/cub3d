/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:23:00 by mchibane          #+#    #+#             */
/*   Updated: 2021/04/01 13:19:53 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_str(uintptr_t value, t_format *flags)
{
	char	*ret;
	char	*str;
	int		size;

	if (value == 0 && flags->dot == 1)
		str = malloc(0);
	else
		str = ft_uitoa_ptr(value, HEX_LOWER);
	size = ft_strlen(str) + 2;
	ret = malloc(sizeof(*ret) * (size + 1));
	if (!ret)
		return (NULL);
	ret[size] = 0;
	ft_memcpy(&ret[2], str, ft_strlen(str));
	ret[0] = '0';
	ret[1] = 'x';
	free(str);
	return (ret);
}

int	print_uint_ptr(t_format *flags, uintptr_t value)
{
	int		ret;
	char	*print;
	char	*str;
	int		size;
	int		len;

	len = 0;
	str = get_str(value, flags);
	flags->dot = 0;
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
