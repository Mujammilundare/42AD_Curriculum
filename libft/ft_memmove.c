/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare <mundare@student.42.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:19:07 by mundare           #+#    #+#             */
/*   Updated: 2024/07/17 12:19:07 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*d_ptr;
	unsigned char	*s_ptr;

	if (!dest && !src)
		return (0);
	d_ptr = (unsigned char *)dest;
	s_ptr = (unsigned char *)src;
	if (dest > src)
	{
		while (len--)
			d_ptr[len] = s_ptr[len];
		return (dest);
	}
	return (ft_memcpy(d_ptr, s_ptr, len));
}
