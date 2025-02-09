/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_radix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:06:03 by mundare           #+#    #+#             */
/*   Updated: 2025/02/09 15:07:10 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_list **a, t_list **b)
{
	while (*b != NULL)
		pa(a, b);
}

void	radix(t_list **a, t_list **b, int size)
{
	int	max_len;
	int	bit_len;
	int	i;
	int	j;

	i = 0;
	bit_len = 0;
	max_len = size - 1;
	while ((max_len >> bit_len) != 0)
		bit_len++;
	while (i < bit_len)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->ind >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		push_back(a, b);
		i++;
	}
}
