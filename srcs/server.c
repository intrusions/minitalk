/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xel <xel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:05:47 by xel               #+#    #+#             */
/*   Updated: 2022/04/25 17:05:47 by xel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	get_message(int signum)
{
	static char	c = 0x00;
	static int	bit = 0x80;

	if (signum == SIGUSR1)
		c |= bit;
	if (bit == 1)
	{
		ft_putchar_fd(c, 1);
		if (!c)
			ft_putchar_fd('\n', 1);
		c = 0x00;
		bit = 0x80;
	}
	else
		bit /= 2;
}

int	main(void)
{
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, get_message);
	signal(SIGUSR2, get_message);
	while (TRUE)
		pause();
}
