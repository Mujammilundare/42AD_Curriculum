/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 08:04:32 by mundare           #+#    #+#             */
/*   Updated: 2025/02/05 08:04:32 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int     validate_arg(char **av);
char    **ft_split(char const *s, char c);
char    **ft_argument_list(int ac, char **av);
void	*ft_calloc(size_t elm_count, size_t elm_size);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int     ft_atoi(const char *str);