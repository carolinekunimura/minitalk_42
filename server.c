/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckunimur <ckunimur@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:46:18 by ckunimur          #+#    #+#             */
/*   Updated: 2023/05/08 17:59:32 by ckunimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int sigusr, siginfo_t *info, void *context)
{
	static char byte;
	static int i;
	
	(void)context;
	if (sigusr == SIGUSR1)
	{
		byte |= (1 << i);
	}
	i++;
	if (i == 8)
	{
		if (byte)
			write(1, &byte, 1);
		else
			write(1, "\n", 1);
		i = 0;
		byte = 0;
	}
	(void)info;
	//kill(info->si_pid, SIGUSR1);
}

int main(void)
{
	struct sigaction	s_sa;
	sigset_t		sigset;
	pid_t			process_id;

	s_sa = (struct sigaction){0};
	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	s_sa.sa_mask = sigset;
	s_sa.sa_flags = SA_SIGINFO;
	s_sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	process_id = getpid();
	ft_printf("PID: %i\n", process_id);

	while (1)
		pause ();
	return (0);
}
