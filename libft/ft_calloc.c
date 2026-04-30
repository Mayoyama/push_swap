/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 12:48:35 by thours            #+#    #+#             */
/*   Updated: 2026/04/11 12:55:27 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*res;
	unsigned char	*ptr;
	size_t			total_size;
	size_t			i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total_size = nmemb * size;
	if (total_size / nmemb != size)
		return (NULL);
	res = malloc(total_size);
	if (!res)
		return (NULL);
	i = 0;
	ptr = (unsigned char *)res;
	while (i < total_size)
		ptr[i++] = 0;
	return (res);
}
