/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mysplit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasna <ahasna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:38:05 by ahasna            #+#    #+#             */
/*   Updated: 2024/09/11 18:43:55 by ahasna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	mystrlcpy(char *dst, const char *src, unsigned int buf_size)
{
	unsigned int	i;

	i = 0U;
	if (!dst || !src || !buf_size)
		return (-1);
	while (i < buf_size - 1 && *src)
		dst[i++] = *src++;
	dst[i] = 0;
	if (i > INT_MAX)
		return (-1);
	return ((int) i);
}

void	freeall(const char **p, size_t index)
{
	if (!p)
		return ;
	while (index--)
		(free((void *) p[index]), p[index] = NULL);
	free(p);
	p = NULL;
}

static const char	**malloc_split(char const *s, char c)
{
	size_t		i;
	size_t		arraysneeded;
	const char	**p;

	i = 0;
	arraysneeded = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
			arraysneeded++;
		while (s[i] && s[i] != c)
			i++;
	}
	p = malloc(sizeof(char *) * (arraysneeded + 1));
	return (p);
}

static char	*create_str(const char *str, char sep)
{
	size_t	i;
	char	*res;

	i = 0;
	while (str[i] != '\0' && str[i] != sep)
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	mystrlcpy(res, str, i + 1);
	return (res);
}

const char	**mysplit(const char *s, const char c)
{
	const char	**p;
	size_t		i;

	i = 0;
	if (!s || !*s)
		return (NULL);
	p = malloc_split(s, c);
	if (!p)
		return (NULL);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != '\0')
		{
			p[i++] = create_str(s, c);
			if (p[i - 1] == NULL)
				return (freeall(p, i - 1), NULL);
		}
		while (*s && *s != c)
			s++;
	}
	p[i] = NULL;
	return (p);
}
