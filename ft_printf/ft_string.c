/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 17:30:36 by mundare           #+#    #+#             */
/*   Updated: 2024/08/05 18:19:50 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

ssize_t	ft_putstr(char *s)
{
	if (!s)
		s = "(null)";
	return (write(1, s, ft_strlen(s)));
}

ssize_t	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
