/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xel <xel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:06:04 by xel               #+#    #+#             */
/*   Updated: 2022/04/25 17:06:04 by xel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(100);
	}
}

static void	ft_send_message(int pid, char *message)
{
	size_t	i;

	i = -1;
	while (++i <= ft_strlen(message))
		ft_send_char(pid, message[i]);
}

int	main(int argc, char **argv)
{
	if (argc == 3 && !(ft_atoi(argv[1]) <= 0))
		ft_send_message(ft_atoi(argv[1]), argv[2]);
	else
		ft_putstr_fd("Incorrect number of arguments", 1);
	return (0);
}
