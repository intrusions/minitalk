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

void	get_message(int signum)
{
	static char	c = 0x00;
	static int	bit = 0x80;

	if (signum == SIGUSR1)
		c |= bit;
	if (bit == 1)
	{
		stock_message(c);
		c = 0x00;
		bit = 0x80;
	}
	else
		bit /= 2;
}

void	stock_message(char c)
{
	static char	*str = NULL;
	char		*dest;
	int			i;

	i = 0;
	dest = NULL;
	dest = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (str)
	{
		while (str[i])
		{
			dest[i] = str[i];
			i++;
		}
	}
	dest[i++] = c;
	dest[i] = 0;
	str = ft_strdup(dest);
	free(dest);
	if (!c)
		str = print_message(str);
}

char	*print_message(char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		ft_putchar_fd(str[i], 1);
	ft_putchar_fd('\n', 1);
	free(str);
	return (NULL);
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
