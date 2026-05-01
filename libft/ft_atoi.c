/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 12:37:37 by thours            #+#    #+#             */
/*   Updated: 2026/04/30 13:45:43 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;
	int	i;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	res = 0;
	while (nptr[i] && ft_isdigit(nptr[i]))
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}
