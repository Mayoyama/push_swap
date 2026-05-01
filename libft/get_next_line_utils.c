/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 09:48:37 by thours            #+#    #+#             */
/*   Updated: 2026/04/30 13:33:38 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	contain_full_line(char *stored)
{
	int	i;

	if (!stored)
		return (0);
	i = 0;
	while (stored[i])
	{
		if (stored[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char *stored, char *buffer)
{
	int		i;
	int		j;
	char	*new_stored;

	if (!stored && !buffer)
		return (NULL);
	new_stored = malloc(ft_strlen_int(stored) + ft_strlen_int(buffer) + 1);
	if (!new_stored)
		return (free(stored), NULL);
	i = 0;
	while (stored && stored[i])
	{
		new_stored[i] = stored[i];
		i++;
	}
	j = 0;
	while (buffer && buffer[j])
		new_stored[i++] = buffer[j++];
	new_stored[i] = '\0';
	free(stored);
	return (new_stored);
}

char	*ft_extract_line(char *str)
{
	char	*res;
	int		size;
	int		i;

	if (!str)
		return (NULL);
	size = 0;
	while (str[size] && str[size] != '\n')
		size++;
	if (str[size] == '\n')
		size++;
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
