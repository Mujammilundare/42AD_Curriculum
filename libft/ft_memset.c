/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare <mundare@student.42.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 11:32:23 by mundare           #+#    #+#             */
/*   Updated: 2024/07/17 11:32:23 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *p;

	p = (unsigned char *)b;
	while (len > 0)
	{
		*(p++) = (unsigned char)c;
		len--;
	}
	return (b);
}
// int main(void)
// {
//     char str[50];
// 	strcpy(str, "Helloworld");
// 	puts(str);
// 	ft_memset(str, '$', 5);
// 	puts(str);
// 	return (0);
// }