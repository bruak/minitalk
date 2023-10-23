/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:39:03 by bsoykan           #+#    #+#             */
/*   Updated: 2023/07/20 12:31:03 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (*s1 && *s1 == *s2 && i < n - 1)
	{
		++s1;
		++s2;
		++i;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
