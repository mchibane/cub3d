/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:48:08 by mchibane          #+#    #+#             */
/*   Updated: 2020/12/10 16:06:16 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;

	if (dstsize < 1)
		return (ft_strlen(src));
	dst_len = ft_strlen(dst);
	i = ft_strlen(dst);
	j = 0;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	if (dstsize < dst_len)
		return (ft_strlen(src) + dstsize);
	return (dst_len + ft_strlen(src));
}
