/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_tools2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasna <ahasna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:25:29 by ahasna            #+#    #+#             */
/*   Updated: 2024/09/11 15:25:47 by ahasna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	mystrncmp(const char *s1, const char *s2, const int n)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (perror("mystrncmp: NULL pointer"), -1);
	if (n < 0)
		return (perror("mystrncmp: negative n"), -1);
	while (s1[i] == s2[i] && i < n)
		i++;
	return (s1[i] - s2[i]);
}

const char	*mystrdup(const char *s)
{
	char	*ret;
	int		i;

	i = -1;
	if (!s)
		return (perror("mystrdup: NULL pointer"), NULL);
	ret = malloc(mystrlen(s) + 1UL);
	if (!ret)
		return (NULL);
	while (s[++i])
		ret[i] = s[i];
	ret[i] = 0;
	return (ret);
}

const char	*mystrndup(const char *s, const int n)
{
	char	*ret;
	int		i;

	i = -1;
	if (!s)
		return (perror("mystrndup: NULL pointer"), NULL);
	ret = malloc(n + 1UL);
	if (!ret)
		return (NULL);
	while (++i < n && s[i])
		ret[i] = s[i];
	ret[i] = 0;
	return (ret);
}

int	len_till_space(const char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (perror("len_till_space: NULL pointer"), -1);
	while (s[++i] && s[i] != ' ')
		;
	return (i);
}

const char	*mycmdjoin(const char *s1, const char *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	ret = (char *) malloc(mystrlen(s1) + mystrlen(s2) + 2UL);
	if (!ret)
		return (NULL);
	while (s1[++i])
		ret[i] = s1[i];
	ret[i++] = '/';
	while (s2[++j])
		ret[i + j] = s2[j];
	ret[i + j] = 0;
	return (ret);
}
