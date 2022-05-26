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

void	ft_get_message(int signum, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit = 128;

	(void)context;
	if (signum == SIGUSR1)
		c |= bit;
	if (bit == 1)
	{
		ft_stock_message(c, info->si_pid);
		c = 0;
		bit = 128;
	}
	else
		bit /= 2;
	kill(info->si_pid, SIGUSR2);
}

void	ft_stock_message(char c, int client_pid)
{
	static char	*str = NULL;
	char		*dest;
	int			i;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!dest)
		return ;
	if (str)
	{
		while (str[i])
		{
			dest[i] = str[i];
			i++;
		}
		free(str);
	}
	dest[i++] = c;
	dest[i] = 0;
	str = ft_strdup(dest);
	if (!c)
	{
		str = ft_print_message(str);
		kill(client_pid, SIGUSR1);
	}
}

char	*ft_print_message(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		ft_putchar_fd(str[i], 1);
	ft_putchar_fd('\n', 1);
	free(str);
	return (NULL);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = ft_get_message;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (TRUE)
		pause();
}
