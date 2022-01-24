/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 22:51:03 by mchibane          #+#    #+#             */
/*   Updated: 2021/03/31 22:40:47 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_prec(t_format *flags, char *dst, char *src, int total_len)
{
	int	start;
	int	len;

	if (total_len == 0)
		return ;
	len = ft_absolute_len(src);
	start = 0;
	if (ft_atoi(src) < 0 && flags->zero == 1)
		ft_memcpy(&dst[start++], src++, 1);
	if (flags->minus == 0 && flags->width > total_len)
	{
		if (ft_atoi(src) < 0)
			start = flags->width - total_len - 1;
		else
			start = flags->width - total_len;
	}
	if (ft_atoi(src) < 0 && flags->zero == 0)
		ft_memcpy(&dst[start++], src++, 1);
	if (len < total_len)
	{
		ft_memset(&dst[start], '0', (total_len - len));
		start += (total_len - len);
	}
	ft_memcpy(&dst[start], src, len);
}

void	uint_prec(t_format *flags, char *dst, char *src, int total_len)
{
	int	start;
	int	len;

	if (total_len == 0)
		return ;
	len = ft_strlen(src);
	start = 0;
	if (flags->minus == 0 && flags->width > total_len)
		start = flags->width - total_len;
	if (len < total_len)
	{
		ft_memset(&dst[start], '0', (total_len - len));
		start += (total_len - len);
	}
	ft_memcpy(&dst[start], src, len);
}
