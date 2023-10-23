/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 14:31:08 by bsoykan           #+#    #+#             */
/*   Updated: 2023/07/20 11:47:41 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int			sng;
	long int	num;

	sng = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sng = -1;
		str++;
	}
	while (*str != 0 && *str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0') * sng;
		if (num > 2147483647)
			return (-1);
		if (num < -2147483648)
			return (0);
		str++;
	}
	return (num);
}
