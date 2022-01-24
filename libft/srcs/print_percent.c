/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:59:34 by mchibane          #+#    #+#             */
/*   Updated: 2021/03/31 23:37:23 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_malloc_size(t_format *flags)
{
	int	ret;

	ret = 1;
	if (flags->width > 1)
		ret = flags->width;
	return (ret);
}

int	print_percent(t_format *flags)
{
	int		ret;
	int		size;
	int		start;
	char	*print;

	start = 0;
	size = get_malloc_size(flags);
	print = malloc(sizeof(*print) * (size + 1));
	if (!print)
		return (-1);
	print[size] = 0;
	padding_handler(print, 1, flags);
	if (flags->minus == 0 && flags->width > 1)
		start = (flags->width) - 1;
	ft_memset(&print[start], '%', 1);
	ret = ft_strlen(print);
	ft_putstr_fd(print, 1);
	free(print);
	return (ret);
}
