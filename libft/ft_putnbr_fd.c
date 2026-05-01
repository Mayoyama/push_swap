/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 09:58:35 by thours            #+#    #+#             */
/*   Updated: 2026/04/14 09:58:36 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbrlong_fd(long nb, int fd)
{
	char	digit;

	if (nb > 9)
		ft_putnbrlong_fd(nb / 10, fd);
	digit = nb % 10 + '0';
	write(fd, &digit, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write(fd, "-", 1);
	}
	ft_putnbrlong_fd(nb, fd);
}
