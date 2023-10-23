/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:37:02 by bsoykan           #+#    #+#             */
/*   Updated: 2023/07/17 12:30:35 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	if (dstsize == '\0')
	{
		return (ft_strlen(src));
	}
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	while (src[i] && dst_len + i < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	if (dst_len > dstsize)
		return (src_len + dstsize);
	return (src_len + dst_len);
}
