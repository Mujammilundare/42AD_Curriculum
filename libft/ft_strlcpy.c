/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:34:09 by mundare           #+#    #+#             */
/*   Updated: 2024/07/02 18:44:50 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i + 1 < len)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < len)
		dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
