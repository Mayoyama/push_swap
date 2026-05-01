/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:28:46 by thours            #+#    #+#             */
/*   Updated: 2026/04/11 10:19:49 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*dest_p;
	const unsigned char	*src_p;

	dest_p = (unsigned char *)dest;
	src_p = (const unsigned char *)src;
	if (dest_p < src_p)
	{
		i = 0;
		while (i < n)
		{
			dest_p[i] = src_p[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			dest_p[i] = src_p[i];
		}
	}
	return (dest);
}
