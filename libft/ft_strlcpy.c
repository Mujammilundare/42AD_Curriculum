/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 14:34:09 by mundare           #+#    #+#             */
/*   Updated: 2024/07/02 18:44:50 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
    size_t i;

    i = 0;
    if (!src || !dest)
        return (0);
    if (len == 0)
        return (ft_strlen(src));
    while (src[i] != '\0' && i < len - 1)
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (ft_strlen(src));
}

// int main(void)
// {
//     char src[] = "abcd";
//     char dest[] = "xxx";
//     ft_strlcpy(dest,src,3);
//     return (0);
// }
