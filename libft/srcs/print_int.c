/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 21:54:49 by mchibane          #+#    #+#             */
/*   Updated: 2021/03/24 12:02:49 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_absolute_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s)
		i++;
	if (ft_atoi(s) < 0)
		i--;
	return (i);
}

static int	get_malloc_size(t_format *flags, char *value, int *len)
{
	int	ret;
	int	sign;

	sign = 0;
	if (ft_atoi(value) < 0)
		sign = 1;
	ret = 0;
	*len = ft_absolute_len(value);
	if (ft_atoi(value) == 0 && flags->dot == 1 && flags->precision == 0)
		*len = 0;
	if (flags->dot == 1 && flags->precision > *len)
		*len = (flags->precision);
	if (flags->width > (*len + sign))
		ret = flags->width;
	else
		ret = (*len + sign);
	if (flags->dot == 1)
		flags->zero = 0;
	return (ret);
}

int	print_int(t_format *flags, int value)
{
	int		ret;
	char	*print;
	char	*str;
	int		size;
	int		len;

	len = 0;
	str = ft_itoa(value);
	size = get_malloc_size(flags, str, &len);
	print = malloc(sizeof(*print) * (size + 1));
	if (!print)
		return (-1);
	print[size] = 0;
	padding_handler(print, len, flags);
	int_prec(flags, print, str, len);
	ft_putstr_fd(print, 1);
	ret = ft_strlen(print);
	free(str);
	free(print);
	return (ret);
}
