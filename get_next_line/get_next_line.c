/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:17:13 by mundare           #+#    #+#             */
/*   Updated: 2024/09/12 19:41:50 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*reader(int fd, char *buf, char *str)
{
	char	*s;
	int		i;

	i = 1;
	while ((!ft_strchr(str, '\n')) && i > 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
		{
			free(buf);
			free(str);
			return (NULL);
		}
		if (i == 0)
		{
			free(buf);
			return (str);
		}
		buf[i] = '\0';
		s = str;
		str = ft_strjoin(str, buf);
		free(s);
	}
	free(buf);
	return (str);
}

char	*current(char *str)
{
	size_t	i;
	char	*s;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	s[i] = '\0';
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		s[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		s[i] = '\n';
	return (s);
}

char	*next(char *str)
{
	size_t	i;
	char	*s;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	s = ft_strdup(str + i);
	if (!s)
		return (NULL);
	free(str);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*str;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	buf = malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	str = reader(fd, buf, str);
	if (!str)
		return (NULL);
	s = current(str);
	str = next(str);
	return (s);
}

int main(void)
{
    int fd;
    char *line;

    fd = open("file.txt",O_RDONLY | O_CREAT);
    while (fd > 0)
    {
        line = get_next_line(fd);
        if(line == NULL)
            break;
        printf("%s",line);
        free(line);
    }
    return (0);
}