/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 22:32:56 by mchibane          #+#    #+#             */
/*   Updated: 2021/03/24 09:54:48 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	padding_handler(char *dst, int len, t_format *flags)
{
	char	filler;
	int		start;
	int		number;

	start = 0;
	number = 0;
	filler = ' ';
	if (flags->zero == 1)
		filler = '0';
	if (flags->width > len)
		number = (flags->width) - len;
	if (flags->minus == 1)
		start = len;
	ft_memset(&dst[start], filler, number);
}
