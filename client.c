/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:43:23 by rnait-el          #+#    #+#             */
/*   Updated: 2023/01/16 03:10:16 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

 void	send(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
}

int	main(int argc, char **argv)
{	
	int server_pid;

	server_pid = ft_atoi(argv[1]) ;
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	if (server_pid <= 0)
		return(1);
	send(ft_atoi(argv[1]), argv[2]);
	return (0);
}