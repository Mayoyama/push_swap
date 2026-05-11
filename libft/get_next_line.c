/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thours <thours@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 09:48:42 by thours            #+#    #+#             */
/*   Updated: 2026/05/11 10:57:15 by thours           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char		*stored;
	char		*line;
	static char	leftover[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	stored = NULL;
	stored = ft_strjoin_gnl(stored, leftover);
	if (!stored)
		return (NULL);
	stored = get_file_content(stored, fd);
	if (!stored)
		return (NULL);
	line = ft_extract_line(stored);
	stored = clear_prev_line(stored);
	ft_strcpy(leftover, stored);
	free(stored);
	return (line);
}

char	*get_file_content(char *stored, int fd)
{
	char	*buffer;
	int		check_copy;

	check_copy = 1;
	while (!contain_full_line(stored))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (free(stored), NULL);
		check_copy = read(fd, buffer, BUFFER_SIZE);
		if (check_copy == -1)
			return (free(buffer), free(stored), NULL);
		buffer[check_copy] = '\0';
		stored = ft_strjoin_gnl(stored, buffer);
		free(buffer);
		if (!stored || check_copy == 0)
			break ;
	}
	if (stored && stored[0] == '\0' && check_copy == 0)
		return (free(stored), NULL);
	return (stored);
}

char	*clear_prev_line(char *stored)
{
	int		i;
	int		j;
	char	*new_stored;

	if (!stored)
		return (NULL);
	if (ft_strlen_int(stored) == 0)
		return (stored);
	i = 0;
	while (stored[i] && stored[i] != '\n')
		i++;
	if (stored[i] == '\n')
		i++;
	new_stored = malloc(ft_strlen_int(stored) - i + 1);
	if (!new_stored)
		return (free(stored), NULL);
	j = 0;
	while (stored[i])
		new_stored[j++] = stored[i++];
	new_stored[j] = '\0';
	free (stored);
	return (new_stored);
}

/*
int	main(void)
{
	int	fd;
	int	line_count = 0;

	fd = open("test.txt", O_RDONLY);

	char *line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
		line_count++;
		free(line);
	}
	printf("\nline count = %d\n", line_count - 1);
	close(fd);
	return (0);
}
*/
