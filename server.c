/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsoykan <bsoykan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:01:56 by bsoykan           #+#    #+#             */
/*   Updated: 2023/10/27 17:00:36 by bsoykan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	handler(int signum)
{
	static int	letter;
	static int	power;

	if (!power)
		power = 128;
	if (signum == SIGUSR1)
		letter += power;
	power /= 2;
	if (power == 0)
	{
		ft_putchar_fd(letter, 1);
		power = 128;
		letter = 0;
	}
	usleep(100);
}

int	main(void)
{
	ft_putstr_fd("\nPID ---------------------------------------> ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n", 1);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
