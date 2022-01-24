/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:30:07 by mchibane          #+#    #+#             */
/*   Updated: 2020/11/23 18:10:02 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int				i;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	i = len - 1;
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	if (!src && !dst)
		return (NULL);
	if (src < dst)
	{
		while (i >= 0)
		{
			ptr_dst[i] = ptr_src[i];
			i--;
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
