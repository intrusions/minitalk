/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 17:43:11 by jucheval          #+#    #+#             */
/*   Updated: 2022/05/26 17:43:11 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define TRUE 1
# define FALSE 0
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	int	received_bit;
}	t_data;

// utils
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *str);
char	*ft_strdup(char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// static
void	ft_received_bit(int signum);
void	ft_received_message(int signum);
void	ft_send_char(int pid, char c);
void	ft_send_message(int pid, char *message);
void	ft_get_message(int signum, siginfo_t *info, void *context);
void	ft_stock_message(char c, int client_pid);
char	*ft_print_message(char *str);

#endif