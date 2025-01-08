/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:17:16 by mundare           #+#    #+#             */
/*   Updated: 2025/01/08 14:17:13 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char *buffer, char *more_buffer)
{
	size_t	i;
	size_t	j;
	size_t	length;
	char	*str;

	if (!buffer)
	{
		buffer = (char *)malloc(1 * sizeof(char));
		buffer[0] = '\0';
	}
	if (!buffer || !more_buffer)
		return (NULL);
	length = ft_strlen(buffer) + ft_strlen(more_buffer);
	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	while (buffer[++i] != '\0')
		str[i] = buffer[i];
	while (more_buffer[j] != '\0')
		str[i++] = more_buffer[j++];
	str[length] = '\0';
	free(buffer);
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
