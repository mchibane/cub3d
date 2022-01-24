/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 15:01:32 by mchibane          #+#    #+#             */
/*   Updated: 2020/11/23 13:55:17 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(int n)
{
	int	count;
	int	nb;

	count = 0;
	nb = n;
	if (n < 0)
	{
		count++;
		nb *= -1;
	}
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	if (count == 0)
		count++;
	return (count);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				size;
	int				i;
	unsigned int	nb;

	size = ft_get_size(n);
	i = size;
	nb = n;
	if (n < 0)
		nb *= -1;
	str = malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	str[i] = 0;
	while (--i > 0)
	{
		str[i] = (nb % 10) + 48;
		nb /= 10;
	}
	if (n < 0)
		str[i] = '-';
	else
		str[i] = (nb % 10) + 48;
	return (str);
}
