/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:17:13 by mundare           #+#    #+#             */
/*   Updated: 2025/01/08 15:29:18 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// 1. malloc buffer
static char	*ft_increase_buffer(int fd, char *buffer)
{
	char	*more_buffer;
	int		bytes_read;

	bytes_read = 1;
	more_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!more_buffer)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && bytes_read)
	{
		bytes_read = read(fd, more_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(more_buffer);
			return (0);
		}
		more_buffer[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, more_buffer);
	}
	free (more_buffer);
	return (buffer);
}

// 2. get line to return
static char	*ft_get_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (0);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	line = (char *)malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

// 3. re-define buffer
char	*ft_new_buffer(char *buffer)
{
	char	*new_buffer;
	size_t	length;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (0);
	}
	length = ft_strlen(buffer) - i;
	new_buffer = (char *)malloc((length + 1) * sizeof(char));
	if (!new_buffer)
		return (NULL);
	i++;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = ft_increase_buffer(fd, buffer);
	if (!buffer)
		return (0);
	line = ft_get_line(buffer);
	buffer = ft_new_buffer(buffer);
	return (line);
}
