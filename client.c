/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:46:33 by ckunimur          #+#    #+#             */
/*   Updated: 2023/05/08 17:59:13 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	received(int sig)
{
	int	count;

	count = 0;
	if (sig == SIGUSR1)
	{
		count++;
		ft_printf("Signal SIGUSR1 received");
	}
	else if (sig == SIGUSR2)
		ft_printf("Signal SIGUSR2 received");
	else
	{
		ft_printf("error > signal fail");
		exit(22);
	}
}

int	check_digit(char *str_pid)
{
	int	i;

	i = 0;
	while (str_pid[i])
	{
		if (str_pid[i] >= '0' && str_pid[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

void	send_bit(char* argv, int pid)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < 8)
		{
			if (*argv >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(5000);
		}
		if (!*argv)
			break ;
		argv++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
		return (ft_printf("error > use: ./client.c <PID> <message> \n"));
	if (check_digit(argv[1]) == 1)
		return (ft_printf("error > wrong PID number! \n"));
	pid = ft_atoi(argv[1]);
	send_bit(argv[2], pid);
}
