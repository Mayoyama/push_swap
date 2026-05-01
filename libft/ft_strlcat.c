/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 09:47:32 by thours            #+#    #+#             */
/*   Updated: 2026/04/11 16:33:33 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;
	size_t	j;

	dst_size = 0;
	src_size = 0;
	while (dst && dst[dst_size])
		dst_size++;
	while (src[src_size])
		src_size++;
	if (dst_size >= size)
		return (src_size + size);
	i = 0;
	while (dst[i])
		i++;
	j = 0;
	while (src[j] && i < size - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (dst_size + src_size);
}
