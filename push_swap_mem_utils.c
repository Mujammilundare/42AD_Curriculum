/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare <mundare@student.42.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:29:55 by mundare           #+#    #+#             */
/*   Updated: 2024/07/18 13:29:55 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len > 0)
	{
		*(p++) = (unsigned char)c;
		len--;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t elm_count, size_t elm_size)
{
	void	*ptr;

	ptr = malloc(elm_count * elm_size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, elm_size * elm_count);
	return (ptr);
}

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