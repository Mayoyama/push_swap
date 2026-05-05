/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: speterse <speterse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:12:49 by speterse          #+#    #+#             */
/*   Updated: 2026/05/05 18:12:50 by speterse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft.h"

void	ft_putdouble_fd(double d, int fd, int decimalplaces)
{
	int		base;
	double	remainder;
	int		digit;

	base = (int)d;
	ft_putnbr_fd(base, fd);
	if (decimalplaces > 0)
	{
		ft_putchar_fd('.', fd);
		remainder = d - (double)base;
		if (remainder < 0)
			remainder = -remainder;
		while (decimalplaces > 0)
		{
			remainder *= 10;
			digit = (int)remainder;
			ft_putnbr_fd(digit, fd);
			remainder -= digit;
			decimalplaces--;
		}
	}
}

void	padded_putnbr_fd(int num, int fd)
{
	if (num < 1000)
		ft_putchar_fd(' ', fd);
	if (num < 100)
		ft_putchar_fd(' ', fd);
	if (num < 10)
		ft_putchar_fd(' ', fd);
	ft_putnbr_fd(num, fd);
}
