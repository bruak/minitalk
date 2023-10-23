/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:38:49 by bsoykan           #+#    #+#             */
/*   Updated: 2023/07/10 16:13:44 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wlen(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static int	count_words(char const *str, char c)
{
	int	i;
	int	count;

	count = 0;
	while (*str)
	{
		i = 0;
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
		str += i;
	}
	return (count);
}

char	**free_all(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *str, char c)
{
	char	**result;
	int		word_index;

	if (!str)
		return (NULL);
	word_index = 0;
	result = (char **) malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!result)
		return (NULL);
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
		{
			result[word_index] = malloc((wlen(str, c) + 1) * sizeof(char));
			if (!result[word_index])
				return (free_all(result));
			ft_strlcpy(result[word_index++], str, wlen(str, c) + 1);
			str += wlen(str, c);
		}
	}
	result[word_index] = NULL;
	return (result);
}
