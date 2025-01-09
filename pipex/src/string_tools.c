/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahasna <ahasna@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:20:52 by ahasna            #+#    #+#             */
/*   Updated: 2024/09/11 18:40:42 by ahasna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	is_absolute_path(const char *str)
{
	if (!str)
		return (perror("is_absolute_path: NULL pointer"), -1);
	if (str[0] == '/' || str[0] == '.')
		return (1);
	return (0);
}

size_t	mystrlen(const char *str)
{
	size_t	i;

	i = -1;
	if (!str)
		return (perror("mystrlen: NULL pointer"), -1);
	while (str[++i])
		;
	return (i);
}

// Returns 0 if at any of the commands are all spaces
int	allspacesdetect(const int argc, const char *const *argv)
{
	int	i;
	int	j;

	i = 1;
	if (!argv)
		return (perror("allspacesdetect: NULL pointer"), -1);
	while (argv[++i] && i < argc - 1)
	{
		j = -1;
		if (!argv[i])
			return (1);
		while (argv[i][++j] == ' ')
			;
		if (argv[i][j] == 0)
			return (1);
	}
	return (0);
}

int	mystrnstr(const char *haystack, const char *needle, const int len)
{
	int	i;
	int	j;

	i = -1;
	if (!needle || !haystack)
		return (perror("mystrstr: NULL pointer"), -1);
	while (haystack[++i] && i < len)
	{
		j = -1;
		while (needle[++j] && i + j < len && haystack[i + j] == needle[j])
			;
		if (needle[j] == 0)
			return (i);
	}
	return (-1);
}

char	*mystrjoin(const char *s1, const char *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (perror("mystrjoin: NULL pointer"), NULL);
	ret = (char *) malloc(mystrlen(s1) + mystrlen(s2) + 1UL);
	if (!ret)
		return (NULL);
	while (s1[++i])
		ret[i] = s1[i];
	while (s2[++j])
		ret[i + j] = s2[j];
	ret[i + j] = 0;
	return (ret);
}
