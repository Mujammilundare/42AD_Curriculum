/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:34:36 by mundare           #+#    #+#             */
/*   Updated: 2024/07/02 18:44:04 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	value;
	char	*str;

	len = ft_strlen(s);
	value = (char)c;
	str = (char *)s;
	while (len >= 0)
	{
		if (str[len] == value)
			return (&str[len]);
		len--;
	}
	return (NULL);
}
