/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 18:34:00 by thours            #+#    #+#             */
/*   Updated: 2026/04/14 10:00:18 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(int n)
{
	long	nb;
	size_t	len;

	nb = n;
	len = 0;
	if (nb < 0)
	{
		nb = -nb;
		len++;
	}
	while (nb > 9)
	{
		nb /= 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	long	nb;
	size_t	i;

	res = malloc(sizeof(char) * (get_len(n) + 1));
	if (!res)
		return (NULL);
	nb = n;
	i = get_len(n);
	res[i--] = '\0';
	if (nb < 0)
		nb = -nb;
	while (nb > 9)
	{
		res[i--] = nb % 10 + '0';
		nb /= 10;
	}
	res[i--] = nb % 10 + '0';
	if (n < 0)
		res[i] = '-';
	return (res);
}
