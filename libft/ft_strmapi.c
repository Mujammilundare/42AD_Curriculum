/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare <mundare@student.42.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:35:00 by mundare           #+#    #+#             */
/*   Updated: 2024/07/18 15:20:45 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
// char uppercase(unsigned int index, char c)  
// {  
// 	if (c >= 'a' && c <= 'z')  
// 		c = c - 'a' + 'A';  
// 	return c;  
// } 
// int main(void)
// {
// 	char org_str[] = "testme";
// 	printf("%s",org_str);
// 	printf("%s",ft_strmapi(org_str,uppercase));
// 	return(0);
// }
