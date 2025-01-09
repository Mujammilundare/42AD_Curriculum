/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbasheer <hbasheer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:39:04 by hbasheer          #+#    #+#             */
/*   Updated: 2024/09/17 16:39:05 by hbasheer         ###   ########.fr       */
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
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		push_back(a, b);
		i++;
	}
}
