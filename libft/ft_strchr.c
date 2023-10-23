/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:38:55 by bsoykan           #+#    #+#             */
/*   Updated: 2023/07/20 12:30:29 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s[0] && !c)
		return ((char *) s);
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *) s + i);
		i++;
	}
	if ((unsigned char) c)
		return (NULL);
	return ((char *) s + i);
}
