/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <mchibane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 18:14:03 by mchibane          #+#    #+#             */
/*   Updated: 2022/01/24 18:17:56 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequal(char const *s1, char const *s2)
{
	return (ft_strlen(s1) == ft_strlen(s2)
		&& ft_strncmp(s1, s2, ft_strlen(s1)) == 0);
}
