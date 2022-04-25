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
	static int	size = 7;

	if (signum == SIGUSR1)
	{
		c += (1 << size);
		size--;
	}
	else if (signum == SIGUSR2)
		size--;
	if (size < 0)
	{
		ft_putchar_fd(c, 1);
		if (!c)
			ft_putchar_fd('\n', 1);
		c = 0x00;
		size = 7;
	}
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
