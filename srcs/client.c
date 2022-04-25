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

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		printf("Le pid est : %d\nLe message est : %s\n", atoi(argv[1]), argv[2]);
		kill(atoi(argv[1]), SIGUSR1);
	}
	else
		printf("Incorrect number of arguments");
	return (0);
}