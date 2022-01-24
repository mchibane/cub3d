/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 12:24:42 by mchibane          #+#    #+#             */
/*   Updated: 2021/03/24 10:00:52 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_malloc_size_str(t_format *flags, char *s, int *len)
{
	int	ret;

	ret = 0;
	*len = ft_strlen(s);
	if ((flags->precision < *len) && flags->dot == 1)
		*len = flags->precision;
	if (flags->width > *len)
		ret = flags->width;
	else
		ret = *len;
	return (ret);
}

static void	pft_strcat(t_format *flags, char *dst, char *src, int len)
{
	int	start;

	start = 0;
	if ((flags->minus == 0) && flags->width > len)
		start = (flags->width) - len;
	ft_memcpy(&dst[start], src, len);
}

int	print_string(t_format *flags, char *str)
{
	int		ret;
	char	*print;
	int		size;
	int		len;

	len = 0;
	if (!str)
		str = "(null)";
	size = get_malloc_size_str(flags, str, &len);
	print = malloc(sizeof(*print) * (size + 1));
	if (!print)
		return (-1);
	print[size] = 0;
	padding_handler(print, len, flags);
	pft_strcat(flags, print, str, len);
	ret = ft_strlen(print);
	ft_putstr_fd(print, 1);
	free(print);
	return (ret);
}
