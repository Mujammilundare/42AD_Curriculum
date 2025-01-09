/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasna <ahasna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 05:10:48 by ahasna            #+#    #+#             */
/*   Updated: 2024/09/11 18:38:27 by ahasna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*empty_file(char **p)
{
	free(*p);
	*p = NULL;
	return (NULL);
}

static char	*nlchr(const char *str)
{
	while (str && *str)
		if (*str++ == (char) '\n')
			return ((char *)--str);
	return (NULL);
}

static void	add_and_free(char **s, unsigned int *i)
{
	char	*tmp;

	*i += BUFFER_SIZE;
	tmp = dup_and_add(*s, BUFFER_SIZE + *i);
	free(*s);
	*s = tmp;
}

static char	*norm_limit(char **p)
{
	char	*line;
	char	*tmp;

	if (nlchr(*p))
	{
		line = memdup(*p, (unsigned long)(nlchr(*p) - *p) + 1UL);
		tmp = memdup(nlchr(*p) + 1UL, better_strlen(nlchr(*p) + 1UL));
		if (!line)
			return (free(tmp), empty_file(p), NULL);
		free(*p);
		*p = dup_and_add(tmp, BUFFER_SIZE + better_strlen(tmp));
		free(tmp);
		tmp = NULL;
		return (line);
	}
	line = dup_and_add(*p, better_strlen(*p));
	tmp = NULL;
	free(*p);
	*p = NULL;
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*p;
	unsigned int	i;
	ssize_t			read_count;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1 || BUFFER_SIZE > 2147483646)
		return (NULL);
	if (!p)
		better_bzero(p = malloc(BUFFER_SIZE + 1U), BUFFER_SIZE + 1U);
	if (!p)
		return (empty_file(&p));
	i = better_strlen(p);
	while (!nlchr(p))
	{
		read_count = read(fd, p + i, BUFFER_SIZE);
		if (read_count < 0 || (!i && !read_count))
			return (empty_file(&p));
		if (read_count < BUFFER_SIZE)
			break ;
		if (!nlchr(p))
			add_and_free(&p, &i);
		if (!p)
			return (empty_file(&p));
	}
	return (norm_limit(&p));
}
