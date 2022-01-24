/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 20:05:09 by mchibane          #+#    #+#             */
/*   Updated: 2021/03/22 20:34:55 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(t_format *flags, int c)
{
	int	ret;

	ret = 0;
	if ((flags->width) > 1 && (flags->minus) == 0)
	{
		while (ret < (flags->width) - 1)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	write(1, &c, 1);
	if ((flags->width) > 1 && (flags->minus) == 1)
	{
		while (ret < (flags->width) - 1)
		{
			write(1, " ", 1);
			ret++;
		}
	}
	ret++;
	return (ret);
}
