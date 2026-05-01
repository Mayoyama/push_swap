/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:29:28 by thours            #+#    #+#             */
/*   Updated: 2026/04/30 13:34:39 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbrlong(long nb)
{
	char	digit;

	if (nb > 9)
		ft_putnbrlong(nb / 10);
	digit = nb % 10 + '0';
	write(1, &digit, 1);
}

void	ft_putnbr_unsigned(unsigned int nb)
{
	char	digit;

	if (nb > 9)
		ft_putnbr_unsigned(nb / 10);
	digit = nb % 10 + '0';
	write(1, &digit, 1);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
		nb = -nb;
	ft_putnbrlong(nb);
}

void	ft_putstr(char *str)
{
	int	i;

	if (!str)
		write(1, "(null)", 6);
	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

void	put_hex_nbr(unsigned long n, int upper)
{
	char	*base;

	if (!upper)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n >= 16)
		put_hex_nbr(n / 16, upper);
	write(1, &base[n % 16], 1);
}
