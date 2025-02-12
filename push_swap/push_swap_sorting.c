/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mundare <mundare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 12:54:22 by mundare           #+#    #+#             */
/*   Updated: 2025/02/12 20:50:50 by mundare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_list *stack)
{
	while (stack != NULL && stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	set_index_a(t_list **a)
{
	t_list	*current;
	t_list	*tmp;
	int		index;

	current = *a;
	while (current)
	{
		tmp = *a;
		index = 0;
		while (tmp)
		{
			if (tmp->data < current->data)
				index++;
			tmp = tmp->next;
		}
		current->ind = index;
		current = current->next;
	}
}
