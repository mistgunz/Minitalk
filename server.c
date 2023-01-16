/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnait-el <rnait-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 00:43:46 by rnait-el          #+#    #+#             */
/*   Updated: 2023/01/16 01:41:07 by rnait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	handler(int sig)
{
	static int				i = 0;
	static unsigned char	c = 0;


	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		ft_putchar_fd(c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1,handler);
	signal(SIGUSR2,handler);
	while (1)
		pause();
	return (0);
}

