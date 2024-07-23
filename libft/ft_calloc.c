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

#include "libft.h"

void	*ft_calloc(size_t elm_count, size_t elm_size)
{
	void	*ptr;

	ptr = malloc(elm_count * elm_size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, elm_size * elm_count);
	return (ptr);
}
