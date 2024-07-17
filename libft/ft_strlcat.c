/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare <mundare@student.42.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:44:31 by mundare           #+#    #+#             */
/*   Updated: 2024/07/17 14:44:31 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	i;
	size_t	des_size;

	des_size = 0;
	while (dest[des_size] != '\0' && des_size < len)
		des_size++;
	i = des_size;
	while (src[des_size - i] && des_size + 1 < len)
	{
		dest[des_size] = src[des_size - i];
		des_size++;
	}
	if (i < len)
		dest[des_size] = '\0';
	return (i + ft_strlen(src));
}
// int main(void)
// {
//     char src[] = "abcd";
//     char dest[] = "1234";
//     ft_strlcat(dest,src,7);
//     return (0);
// }