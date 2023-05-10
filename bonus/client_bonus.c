/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:46:33 by ckunimur          #+#    #+#             */
/*   Updated: 2023/05/10 16:57:40 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_i = 0;

void	received(int sigusr, siginfo_t *info, void *context)
{
	if (sigusr == SIGUSR1)
		g_i = 0;
	else if (sigusr == SIGUSR2)
		ft_printf("Server confirmation received\n");
	(void)info;
	(void)context;
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

void	send_bit(char *argv, int pid)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < 8)
		{
			if (g_i == 0)
			{
				g_i = 1;
				if (*argv >> i & 1)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
				i++;
			}
			usleep(100);
		}
		if (!*argv)
			break ;
		argv++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	s_sa;
	sigset_t			sigset;
	pid_t				pid;

	if (argc != 3)
		return (ft_printf("error > use: ./client.c <PID> <message> \n"));
	if (check_digit(argv[1]) == 1)
		return (ft_printf("error > wrong PID number! \n"));
	pid = ft_atoi(argv[1]);
	s_sa = (struct sigaction){0};
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	s_sa.sa_mask = sigset;
	s_sa.sa_flags = SA_SIGINFO;
	s_sa.sa_sigaction = received;
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	send_bit(argv[2], pid);
}
