/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasna <ahasna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 05:10:51 by ahasna            #+#    #+#             */
/*   Updated: 2024/09/11 15:58:34 by ahasna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	better_strlen(const char *str)
{
	size_t	i;

	i = 0U;
	while (str && str[i])
		i++;
	return (i);
}

void	better_bzero(void *s, size_t n)
{
	while (s && n--)
		*(char *) s++ = (char) '\0';
}

char	*dup_and_add(const char *s, unsigned long c)
{
	char			*p;
	unsigned int	j;

	if (!s)
		return (NULL);
	j = better_strlen(s);
	if (j > c)
		c = j;
	p = malloc(c + 1U);
	if (!p)
		return (NULL);
	better_bzero(p, c + 1U);
	while (j--)
		p[j] = s[j];
	return (p);
}

char	*memdup(const char *s, unsigned long c)
{
	char	*p;

	if (!s || !c)
		return (NULL);
	p = malloc(c + 1U);
	if (!p)
		return (NULL);
	better_bzero(p, c + 1U);
	while (c--)
		p[c] = s[c];
	return (p);
}
