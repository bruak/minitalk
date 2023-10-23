/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:38:03 by bsoykan           #+#    #+#             */
/*   Updated: 2023/07/12 14:15:48 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*source;
	int			i;

	if (!dst && !src)
		return ((void *) dst);
	dest = dst;
	source = src;
	if (dest < source)
	{
		ft_memcpy(dest, source, len);
		return (dst);
	}
	i = len - 1;
	while (i >= 0)
	{
		dest[i] = source[i];
		i--;
	}
	return (dst);
}
