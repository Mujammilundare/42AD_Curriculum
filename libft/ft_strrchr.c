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

char	*ft_strrchr(const char *s, int i)
{
	int		len;

	len = ft_strlen(s);
	if (i == 0)
		return ((char *)s + len);
	while (len >= 0)
	{
		if (s[len] == i)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}
// int main(void)
// {
// 	char *str = "abcaef";
// 	char *output = ft_strrchr(str,97);
// 	printf("%s", output);
//     return (0);
// }