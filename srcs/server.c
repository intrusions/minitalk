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

void    ft_get_data(int sig)
{
	(void)sig;
	printf("la il y'as un signal");
}

int	main()
{
	printf("The PID of the preccessus is : %d\n", getpid());
	signal(SIGUSR1, ft_get_data);
	signal(SIGUSR2, ft_get_data);
	pause();
}