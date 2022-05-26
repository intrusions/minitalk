/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xel <xel@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:06:01 by xel               #+#    #+#             */
/*   Updated: 2022/04/25 17:06:01 by xel              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define TRUE 1
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	int	received_bit;
}	t_data;

size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_strdup(char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_get_message(int signum, siginfo_t *info, void *context);
void	ft_stock_message(char c, int client_pid);
char	*ft_print_message(char *str);

#endif