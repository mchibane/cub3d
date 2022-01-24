/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:21:25 by mchibane          #+#    #+#             */
/*   Updated: 2021/03/24 10:50:53 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_get_size(unsigned int n)
{
	unsigned int	count;

	count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	if (count == 0)
		count++;
	return (count);
}

char	*ft_uitoa(unsigned int n)
{
	char			*str;
	unsigned int	size;
	unsigned int	i;

	size = ft_get_size(n);
	i = size;
	str = malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	str[i] = 0;
	while (--i > 0)
	{
		str[i] = (n % 10) + 48;
		n /= 10;
	}
	str[i] = (n % 10) + 48;
	return (str);
}
