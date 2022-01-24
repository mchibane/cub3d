/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:41:16 by mchibane          #+#    #+#             */
/*   Updated: 2021/03/31 21:51:20 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_get_size(unsigned int n, char *base)
{
	unsigned int	count;

	count = 0;
	while (n != 0)
	{
		n /= ft_strlen(base);
		count++;
	}
	if (count == 0)
		count++;
	return (count);
}

char	*ft_uitoa_base(unsigned int n, char *base)
{
	char			*str;
	unsigned int	size;
	unsigned int	i;
	int				base_len;

	base_len = ft_strlen(base);
	size = ft_get_size(n, base);
	i = size;
	str = malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	str[i] = 0;
	while (--i > 0)
	{
		str[i] = base[n % base_len];
		n /= base_len;
	}
	str[i] = base[n % base_len];
	return (str);
}
