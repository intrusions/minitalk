/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:43:37 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/26 17:43:37 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	ft_received_bit(int signum)
{
	(void)signum;
	g_data.received_bit = 1;
}

void	ft_received_message(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_putstr_fd("received\n", 1);
		exit(0);
	}
}

void	ft_send_char(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		sleep(1);
		while (!g_data.received_bit)
		{
			pause();
			g_data.received_bit = 0;
		}
		i--;
	}
}

void	ft_send_message(int pid, char *message)
{
	size_t	i;

	i = -1;
	while (++i <= ft_strlen(message))
		ft_send_char(pid, message[i]);
}

int	main(int argc, char **argv)
{
	g_data.received_bit = 0;
	signal(SIGUSR1, ft_received_message);
	signal(SIGUSR2, ft_received_bit);
	if (argc == 3 && !(ft_atoi(argv[1]) <= 0))
		ft_send_message(ft_atoi(argv[1]), argv[2]);
	else
		ft_putstr_fd("Incorrect number of arguments", 1);
	return (0);
}
