/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:17:13 by mundare           #+#    #+#             */
/*   Updated: 2025/01/16 15:21:38 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*nxt_remainder(char *s_remainder)
{
	char	*new_remainder;
	char	*str;
	int		len;

	str = ft_strchr(s_remainder, '\n');
	if (!str)
	{
		new_remainder = NULL;
		return (ft_free(&s_remainder));
	}
	else
		len = (str - s_remainder) + 1;
	if (!s_remainder[len])
		return (ft_free(&s_remainder));
	new_remainder = ft_substr(s_remainder, len, ft_strlen(s_remainder) - len);
	ft_free(&s_remainder);
	if (!new_remainder)
		return (NULL);
	return (new_remainder);
}

char	*new_line(char *s_remainder)
{
	char	*line;
	char	*str;
	int		len;

	str = ft_strchr(s_remainder, '\n');
	len = (str - s_remainder) + 1;
	line = ft_substr(s_remainder, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*reader(int fd, char *s_remainder)
{
	int		i;
	char	*temp_buf;

	i = 1;
	temp_buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp_buf)
		return (ft_free(&s_remainder));
	temp_buf[0] = '\0';
	while (i > 0 && !ft_strchr(temp_buf, '\n'))
	{
		i = read(fd, temp_buf, BUFFER_SIZE);
		if (i > 0)
		{
			temp_buf[i] = '\0';
			s_remainder = ft_strjoin(s_remainder, temp_buf);
		}
	}
	free(temp_buf);
	if (i == -1)
		return (ft_free(&s_remainder));
	return (s_remainder);
}

char	*get_next_line(int fd)
{
	static char	*s_remainder;
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((s_remainder && !ft_strchr(s_remainder, '\n')) || !s_remainder)
		s_remainder = reader(fd, s_remainder);
	if (!s_remainder)
		return (NULL);
	line = new_line(s_remainder);
	if (!line)
		return (ft_free(&s_remainder));
	s_remainder = nxt_remainder(s_remainder);
	return (line);
}
