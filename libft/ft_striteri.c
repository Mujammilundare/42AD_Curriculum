/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare <mundare@student.42.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:33:45 by mundare           #+#    #+#             */
/*   Updated: 2024/07/18 15:29:06 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
// void printWithIndex(unsigned int index, char *c)  
// {  
//     printf("Character at index %u: %c\n", index, *c);  
// }  

// int main()  
// {  
//     char str[] = "hello world";  

//     printf("Original String: %s\n", str);  

//     ft_striteri(str, printWithIndex);  

//     return 0;  
// }  
