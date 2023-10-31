/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:40:08 by bsoykan           #+#    #+#             */
/*   Updated: 2023/10/27 16:35:17 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

int	checker(int ac, int pi)
{
	if (ac < 3)
	{
		ft_putstr_fd("ErRor: arguments not enough!!!\n", 2);
		return (0);
	}
	else if (ac > 3)
	{
		ft_putstr_fd("ErRor: arguments too much!!!\n", 2);
		return (0);
	}
	else if (pi == -1)
	{
		ft_putstr_fd("Bro not do that ok?, this is not win u cant use f5\n", 2);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		i;
	int		pid;
	int		power;
	char	*str;

	power = 128;
	i = -1;
	pid = ft_atoi(av[1]);
	str = av[2];
	if (!checker(ac, pid))
		return (-1);
	while (str[++i])
	{
		while (power >= 1)
		{
			if (str[i] & power)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			power /= 2;
			usleep(100);
		}
		power = 128;
	}
	return (0);
}
