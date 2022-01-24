/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:02:59 by mchibane          #+#    #+#             */
/*   Updated: 2020/12/10 15:19:19 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	nbr;

	nbr = nb;
	if (fd != -1)
	{
		if (nbr < 0)
		{
			ft_putchar_fd('-', fd);
			nbr *= -1;
		}
		if (nbr > 9)
		{
			ft_putnbr_fd((nbr / 10), fd);
			ft_putchar_fd(((nbr % 10) + 48), fd);
		}
		else
			ft_putchar_fd(((nbr % 10) + 48), fd);
	}
}
