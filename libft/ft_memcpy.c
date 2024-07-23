/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare <mundare@student.42.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:07:58 by mundare           #+#    #+#             */
/*   Updated: 2024/07/17 12:07:58 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d_ptr;
	const unsigned char	*s_ptr;

	if (!dest && !src)
		return (0);
	d_ptr = (unsigned char *)dest;
	s_ptr = (unsigned char *)src;
	while (n--)
		*d_ptr++ = *s_ptr++;
	return (dest);
}
